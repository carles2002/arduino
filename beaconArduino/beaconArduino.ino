
// --------------------------------------------------------------
// Carles Marti Femenia
// 20-09-2023
// --------------------------------------------------------------

#include <BLEAdvertising.h>
#include <BLECentral.h>
#include <BLECharacteristic.h>
#include <BLEClientCharacteristic.h>
#include <BLEClientService.h>
#include <BLEConnection.h>
#include <BLEDiscovery.h>
#include <BLEGatt.h>
#include <BLEPeriph.h>
#include <BLEScanner.h>
#include <BLESecurity.h>
#include <BLEService.h>
#include <BLEUuid.h>
#include <bluefruit_common.h>
#include <bluefruit.h>


// --------------------------------------------------------------
// --------------------------------------------------------------
//#include <bluefruit.h>

#include "./libraries/LED.h"
#include "./libraries/PuertoSerie.h"


// --------------------------------------------------------------
// --------------------------------------------------------------
namespace Globales
{

    LED elLED ( /* NUMERO DEL PIN LED = */ 7 );

    PuertoSerie elPuerto(/* velocidad = */ 115200); // 115200 o 9600 o ...

    
};


// --------------------------------------------------------------
// --------------------------------------------------------------
#include "./libraries/EmisoraBLE.h"
#include "./libraries/Publicador.h"
#include "./libraries/Medidor.h"

// --------------------------------------------------------------
// --------------------------------------------------------------

namespace Globales
{

    Publicador elPublicador;

    Medidor elMedidor;

}; // namespace

// --------------------------------------------------------------
// --------------------------------------------------------------
void inicializarPlaquita()
{

    // Aquí va el codigo para inicializar algún componente necesario del ESP

} // ()

// setup ()

// --------------------------------------------------------------
// --------------------------------------------------------------

// Creación de las variables globales y de componentes necesarios para la ESP
void setup()
{
    Globales::elPuerto.esperarDisponible();

    
    inicializarPlaquita();

    
    
    Globales::elPublicador.encenderEmisora();

   
    
    Globales::elMedidor.iniciarMedidor();

    
    esperar(1000);

    Globales::elPuerto.escribir("---- setup(): fin ---- \n ");

} 
inline void lucecitas() {
  using namespace Globales;

  elLED.brillar( 100 ); // 100 encendido
  esperar ( 100 ); //  100 apagado
  elLED.brillar( 100 ); // 100 encendido
  esperar ( 100 ); //  100 apagado
  Globales::elLED.brillar( 100 ); // 100 encendido
  esperar ( 100 ); //  100 apagado
  Globales::elLED.brillar( 1000 ); // 1000 encendido
  
} // ()

// --------------------------------------------------------------
// loop ()
// --------------------------------------------------------------
namespace Loop {
  uint8_t cont = 0;
};

// ..............................................................
// ..............................................................
void loop () {

  using namespace Loop;
  using namespace Globales;

  cont++;

  elPuerto.escribir( "\n---- loop(): empieza " );
  elPuerto.escribir( cont );
  elPuerto.escribir( "\n" );

  // Pequeño aviso de luces que indica si se esta ejecutando correctamente
  lucecitas();

  // 
  // mido y publico
  // 
  int valorCO2 = elMedidor.medirCO2();

  //Sobreescribir el valor enviado por el indicado
  valorCO2= 69;
  
  elPublicador.publicarCO2( valorCO2,
							cont,
							1000 // intervalo de emisión
							);
  
  

  esperar( 500 );

  elPublicador.laEmisora.detenerAnuncio();
  
  // 
  // 
  // 
  elPuerto.escribir( "---- loop(): acaba **** " );
  elPuerto.escribir( cont );
  elPuerto.escribir( "\n" );
  
} // loop ()
// --------------------------------------------------------------
// --------------------------------------------------------------
// --------------------------------------------------------------
// --------------------------------------------------------------
