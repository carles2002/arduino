#include <Wire.h>

#define SENSOR_ADDRESS 0x53
#define VGAS 5
#define VREF 28
#define VTEMP 29

void setup() {
  Wire.begin();
  Serial.begin(9600);
 

}

void loop() {
  // Read the ozone data
  int ozone_data = analogRead(A3);
  int ozone_ref = analogRead(A4);
  int ozone_temp = analogRead(A5);

  // Convert the ozone data to a float
  float ozone = ozone_data / 1024.0;
  double ozone_r = ozone_ref / 1024.0;
  double ozone_temp2 = (ozone_temp/1023.0);
  double ozone_te = (ozone_temp2 * 87)-18;
  float v_medida = ozone - ozone_r;

  // Print the ozone data

for(int i = 0; i<100; i++){
     Serial.println("");
  }

 
  Serial.print("Ozone: ");
  Serial.print(ozone, 2);
  Serial.println("ppb");

  Serial.print("REF: ");
  Serial.print(ozone_r, 2);
  Serial.println("");



  Serial.print("TEMP: ");
  Serial.print(ozone_te);

  

  delay(1000);
}
