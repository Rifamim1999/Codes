#include <SD.h>
#include <SPI.h>
File myFile;
void setup() {

 Serial.print("Initializing SD card. . .");
  if (!SD.begin(10)) {      //This opens the communication of CS pin to the Arduino Board and if it is not connected the initialization will failed.
    Serial.println("Initialization failed!");
    return;
  }
// And if successful this will print.
  Serial.println("Initialization done.");  
Serial.println("Creating test.txt. . ." );
myFile = SD.open("test.txt", FILE_WRITE);  //test.txt is the file name to be created and FILE_WRITE is a command to create file.
myFile.close();  //Closing the file
if (SD.exists("test.txt")) { // If the file test.txt exist.
    Serial.println("The test.txt exists.");
  } else { // And if not
    Serial.println("The test.txt doesn't exist.");
  }
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("Testing 1, 2, 3."); //Input the *Testing 1, 2, 3.* inside the file.
    myFile.close(); // Close the file after opening
    Serial.println("Done."); //Display this if the file was successfully written.
  } 
  myFile = SD.open("test.txt"); //Open the file
  if (myFile) {
    
    Serial.println("test.txt:");
    while (myFile.available()) { // If the file is present execute loop until done.
        Serial.write(myFile.read()); //Reading the text inside the file
    }
    myFile.close(); //Close the file after opening
  } else { //Display message if it was unsuccessfully opened.
    Serial.println("Error opening test.txt");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
