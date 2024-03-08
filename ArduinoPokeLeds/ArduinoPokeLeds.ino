
#include <Firebase_ESP_Client.h>
#include <WiFi.h>
#include <addons/TokenHelper.h>
#include <ArduinoJson.h>
#define FIREBASE_USE_PSRAM

const char* WIFI_SSID = "PAIN";//el nombre de la red
const char* WIFI_PASSWORD = "carpio12345";//la contraseña de la red
//Recursos de Firebase
const char* API_KEY = "AIzaSyAinG4XIrtlPkA7VjcvgvJQ9_6HaGST5kg";
const char* FIREBASE_PROJECT_ID = "pokeapileds";

//CONFIGURAR UN EMAIL Y CONTRASEÑA EN AUTHENTICATION de Firebase
const char* USER_EMAIL = "espcheicon@chacon.com";
const char* USER_PASSWORD = "espCheicon";

//Define Firebase Data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

const int LEDR = 23;
const int LEDG = 22;
const int LEDB = 21;

//Funcion para configuara WiFi
void setupWiFi() {
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
}

void setupFirebase() {
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.token_status_callback = tokenStatusCallback;  // Ver addons/TokenHelper.h
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void setup() {
  Serial.begin(115200);
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);//Verificamos la version
  setupWiFi();//Llamamos la funcion de configuración wifi
  setupFirebase();//Llamamos la funcion de configuración Firebase
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}

void loop() {
String path = "Pokemon";//RUTA DE COLECCION
  FirebaseJson json;

  if (Firebase.Firestore.getDocument(&fbdo, FIREBASE_PROJECT_ID, "", path.c_str(), "")) {

    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, fbdo.payload().c_str());

    if (!error) {
      for (JsonObject document : doc["documents"].as<JsonArray>()) {
        const char* document_name = document["name"];//PARAMETRO NOMBRE == ID Documento
        //Serial.print(document);
        const char* state = document["fields"]["Color"]["stringValue"];//PARAMETRO DE CAMPOS A REVISAR
        Serial.print(" : ");
        if (strstr(document_name, "Color") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
        if(strstr(state,"Plomo")!= nullptr){
            setColor(96, 162, 185); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"Celeste")!= nullptr){
              setColor(36, 129, 240); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"VerdeO")!= nullptr){
              setColor(151, 166, 29); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"AzulN")!= nullptr){
              setColor(79, 96, 226); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"Amarillo")!= nullptr){
              setColor(250, 193, 0); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"Morado")!= nullptr){
              setColor(111, 63, 112); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"Rojo")!= nullptr){
              setColor(230, 34, 35); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"Rosa")!= nullptr){
              setColor(239, 112, 240); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"AzulC")!= nullptr){
              setColor(61, 217, 255); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"Violeta")!= nullptr){
              setColor(255, 129, 0); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"Blanco")!= nullptr){
              setColor(160, 162, 160); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"VerdeC")!= nullptr){
              setColor(0, 255, 0); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"Naranja")!= nullptr){
              setColor(239, 63, 12); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"CafeC")!= nullptr){
              setColor(175, 170, 129); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"Negro")!= nullptr){
              setColor(78, 63, 60); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"Cafe")!= nullptr){
              setColor(145, 79, 26); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"MoradoO")!= nullptr){
              setColor(145, 62, 203); // Invertido: ()
          }
          //---------------------------------
          else if(strstr(state,"MoradoC")!= nullptr){
              setColor(130, 186, 24); // Invertido: ()
          }
          //---------------------------------
          else{
              setColor(0,0,0); // Invertido: ()
          }

          //---------------------------------aaaaa

        }
          delay(1000); // Esperar 500 MILIS antes de la próxima lectura
    }
  } 
}
}
void setColor(int red, int green, int blue) {
  analogWrite(LEDR, red);
  analogWrite(LEDG, green);
  analogWrite(LEDB, blue);
}
