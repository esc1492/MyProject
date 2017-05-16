/* Dynamixel Model Scan

 Searches through all valid IDs to find all dynamixel devices currently on
 the bus, and uses the Model Number to identify the device by name
 ported from Dxl_Model_Scan by ROBOTIS CO,.LTD.
*/
/* Serial device defines for dxl bus */
#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP

/* Dynamixel ID defines */
#define ID_Left_Wheel 1
#define ID_Right_Wheel 2

int ModelNumber;
int Version;
int ID;
int BaudRate;
int DelayTiem;
int CWAngleLimit;
int CCWAngleLimit;
int ControlMode;
int LimitTemperature;
int LowerLimitVoltage;
int UpperLimitVoltage;
int MaxTorque;
int ReturnLevel;
int AlarmShutdown;
 
Dynamixel Dxl(DXL_BUS_SERIAL1);

void setup(void) 
{
    // put your setup code here, to run once:
    
    // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
    Dxl.begin(3);  
  
    pinMode(BOARD_LED_PIN, OUTPUT);
    
//    Dxl.writeByte(ID_Left_Wheel, 12, 65);
//    Dxl.writeByte(ID_Left_Wheel, 0x13, 60);
//    Dxl.writeByte(ID_Left_Wheel, 0x14, 90);
//    Dxl.writeWord(ID_Left_Wheel, 0x15, 1023);
//    Dxl.writeByte(ID_Left_Wheel, 0x17, 2);
//    Dxl.writeByte(ID_Left_Wheel, 18, 36);
  
    // Waits 5 seconds for you to open the console 
    //(open too quickly after downloading new code, and you will get errors
    delay(5000);
    SerialUSB.print("Send any value to continue...\n");
    
    while(!SerialUSB.available())
    {
      delay(1000);
      digitalWrite(BOARD_LED_PIN, LOW);
      SerialUSB.print("Send any value to continue...\n");
      delay(1000);
      digitalWrite(BOARD_LED_PIN, HIGH);
    }
}

void loop(void) 
{
    ModelNumber = Dxl.readWord(ID_Left_Wheel, 0);
    Version = Dxl.readByte(ID_Left_Wheel, 2);
    ID = Dxl.readByte(ID_Left_Wheel, 3);
    BaudRate = Dxl.readByte(ID_Left_Wheel, 4);
    DelayTiem = Dxl.readByte(ID_Left_Wheel, 5);
    CWAngleLimit = Dxl.readWord(ID_Left_Wheel, 6);
    CCWAngleLimit = Dxl.readWord(ID_Left_Wheel, 8);
    ControlMode = Dxl.readByte(ID_Left_Wheel, 11);
    LimitTemperature = Dxl.readByte(ID_Left_Wheel, 12);
    LowerLimitVoltage = Dxl.readByte(ID_Left_Wheel, 13);
    UpperLimitVoltage = Dxl.readByte(ID_Left_Wheel, 14);
    MaxTorque = Dxl.readWord(ID_Left_Wheel, 15);
    ReturnLevel = Dxl.readByte(ID_Left_Wheel, 17);
    AlarmShutdown = Dxl.readByte(ID_Left_Wheel, 18);
    
    SerialUSB.print("\nModel Number : ");
    SerialUSB.print(ModelNumber);
    
    SerialUSB.print("\nVersion of Firmware : ");
    SerialUSB.print(Version);
    
    SerialUSB.print("\nID : ");
    SerialUSB.print(ID);
    
    SerialUSB.print("\nBaud Rate : ");
    SerialUSB.print(BaudRate);
    
    SerialUSB.print("\nDelay Time : ");
    SerialUSB.print(DelayTiem);
    
    SerialUSB.print("\nCW Angle Limit : ");
    SerialUSB.print(CWAngleLimit);
    
    SerialUSB.print("\nCCW Angle Limit : ");
    SerialUSB.print(CCWAngleLimit);
    
    SerialUSB.print("\nControl Mode : ");
    SerialUSB.print(ControlMode);
    
    SerialUSB.print("\nLimit Temperature : ");
    SerialUSB.print(LimitTemperature);
    
    SerialUSB.print("\nLower Limit Voltage : ");
    SerialUSB.print(LowerLimitVoltage);
    
    SerialUSB.print("\nUpper Limit Voltage : ");
    SerialUSB.print(UpperLimitVoltage);
    
    SerialUSB.print("\nMax Torque : ");
    SerialUSB.print(MaxTorque);
    
    SerialUSB.print("\nReturn Level : ");
    SerialUSB.print(ReturnLevel);
    
    SerialUSB.print("\nAlarm Shutdown : ");
    SerialUSB.print(AlarmShutdown);
    
    SerialUSB.print("\nP Gain : ");
    SerialUSB.print(Dxl.readByte(ID_Left_Wheel, 29));
  
  while(1)
  {
    digitalWrite(BOARD_LED_PIN, LOW);
    delay(100);
    digitalWrite(BOARD_LED_PIN, HIGH);
    delay(100);
  }
}

