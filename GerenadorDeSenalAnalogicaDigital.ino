/*
Generador de señales analógicas y digitales.

Capaz de generar señal analógica lineal variable de 0-5Vdc, 
y una señal digital cuadrada variable en Hz y amplitud de onda. 
*/


const int digPin = A1;
const int anaPin = A2;
const int hzPin = A3;
float anaValueV;
float digValueV;
int anaValue;
int digValue;
int hzValue;
int anaValueP;
int digValueP;
int hzValueP;
int anaValueD;
int digValueD;
int anaValuePA;
int digValuePA;
int hzValuePA = 0;
String stringHz;

void setup() 
{
  
   Serial.begin(9600);
   pinMode(3, OUTPUT);
   pinMode(6, OUTPUT);
   Serial.println("Grnerador de senales analogicas y digitales");
   Serial.println("           by. TecnoTalayotic");

}



void loop() 
{

   digValue = analogRead(digPin);
   digValueV = fmap(digValue, 0, 1024, 0.0, 5.0);   
   digValueP = map(digValue, 0, 1024, 0, 100);
   digValueD = map(digValue, 0, 1024, 0, 255);  

         
   anaValue = analogRead(anaPin);          
   anaValueV = fmap(anaValue, 0, 1024, 0.0, 5.0);   
   anaValueP = map(anaValue, 0, 1024, 0, 100); 
   anaValueD = map(anaValue, 0, 1024, 0, 256);
   
   hzValue = analogRead(hzPin);
   hzValueP = map(hzValue, 0, 1024, 0, 14);

if (hzValueP == hzValuePA)
  {
    
  }
  else if (hzValue <= 78)
    {
      // Pines D3 y D11 - 62,5 kHz
      stringHz = String("62,2 kHz pwm rapido");
      TCCR2B = 0b00000001 ; // x1
      TCCR2A = 0b00000011 ; // pwm rápido
    }
    else if (hzValue <= 156)
      {
        // Pines D3 y D11 - 31,4 kHz
        stringHz = String("31,4 kHz fase correcta");
        TCCR2B = 0b00000001 ; // x1
        TCCR2A = 0b00000001 ; // fase correcta
      }
      else if (hzValue <= 234)
        {
          // Pines D3 y D11 - 8 kHz
         stringHz = String("8 kHz pwm rapido");
          TCCR2B = 0b00000010 ; // x8
          TCCR2A = 0b00000011 ; // pwm rápido
        }
        else if (hzValue <= 312)
          {
            // Pines D3 y D11 - 4 kHz
           stringHz = String("4 kHz fase correcta");
            TCCR2B = 0b00000010 ; // x8
            TCCR2A = 0b00000001 ; // fase correcta
          }
          else if (hzValue <= 390)
          {
            // Pines D3 y D11 - 2 kHz
           stringHz = String("2 kHz pwm rapido");
            TCCR2B = 0b00000011 ; // x32
            TCCR2A = 0b00000011 ; // pwm rápido
          }
          else if (hzValue <= 486)
            {
              // Pines D3 y D11 - 980 Hz
              stringHz = String("980 Hz fase correcta");
              TCCR2B = 0b00000011 ; // x32
              TCCR2A = 0b00000001 ; // fase correcta
            }
            else if (hzValue <= 546)
              {
                // Pines D3 y D11 - 980 Hz
                stringHz = String("980 Hz pwm rapido");
                TCCR2B = 0b00000100 ; // x64
                TCCR2A = 0b00000011 ; // pwm rápido
              }
              else if (hzValue <= 624)
                {
                  // Pines D3 y D11 - 980 Hz - predeterminado
                 stringHz = String("980 Hz fase correcta");
                  TCCR2B = 0b00000100 ; // x64
                  TCCR2A = 0b00000001 ; // fase correcta
                }
                else if (hzValue <= 702)
                  {
                    // Pines D3 y D11 - 490 Hz
                    stringHz = String("490 Hz pwm rapido");
                    TCCR2B = 0b00000101 ; // x128
                    TCCR2A = 0b00000011 ; // pwm rápido
                  }
                else if (hzValue <= 780)
                  {
                    // Pines D3 y D11 - 245 Hz
                    stringHz = String("245 Hz fase correcta");
                    TCCR2B = 0b00000101 ; // x128
                    TCCR2A = 0b00000001 ; // fase correcta
                  }
                  else if (hzValue <= 858)
                    {
                      // Pines D3 y D11 - 245 Hz
                      stringHz = String("245 Hz pwm rapido");
                      TCCR2B = 0b00000110 ; // x256
                      TCCR2A = 0b00000011 ; // pwm rápido
                    }
                    else if (hzValue <= 936)
                      {
                        // Pines D3 y D11 - 122 Hz
                        stringHz = String("122 Hz fase correcta");
                        TCCR2B = 0b00000110 ; // x256
                        TCCR2A = 0b00000001 ; // fase correcta
                      }
                      else if (hzValue <= 1014)
                        {
                          // Pines D3 y D11 - 60 Hz
                         stringHz = String("60 Hz pwm rapido");
                          TCCR2B = 0b00000111 ; // x1024
                          TCCR2A = 0b00000011 ; // pwm rápido
                        }
                        else if (hzValue <= 1025)
                          {
                            // Pines D3 y D11 - 30 Hz
                           stringHz = String("30 Hz fase correcta");
                            TCCR2B = 0b00000111 ; // x1024
                            TCCR2A = 0b00000001 ; // fase correcta
                          }
  
analogWrite(3, 15 + digValueD);
analogWrite(6, anaValueD);



  if (digValueP != digValuePA or anaValueP != anaValuePA or hzValueP != hzValuePA)
  {

            Serial.println(".");
            Serial.print("Salida digital ");
            Serial.print(digValueP);
            Serial.print("%");
            Serial.print("  //  ");
            Serial.print(digValueV);                     
            Serial.print("V");
            Serial.print("  //  ");
            Serial.print(digValueD);
            Serial.print(" Senal digital 0 - 255");
            Serial.print("  //  ");
            Serial.println(stringHz);
           
            Serial.print("Salida analogica ");
            Serial.print(anaValueP);
            Serial.print("%");
            Serial.print("  //  ");
            Serial.print(anaValueV);                     
            Serial.print("V");
            Serial.print("  //  ");
            Serial.print(anaValue);
            Serial.println(" Senal analogica 0 - 1023");

            digValuePA = digValueP;
            hzValuePA = hzValueP;
            anaValuePA = anaValueP;

            
  }

              else
              {

              }
                    
delay(1000);
}
// cambio de escala entre floats
float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
   return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
