
// --------------------------------------------------------------
// Carles Marti Femenia
// 20-09-2023
// --------------------------------------------------------------

#ifndef LED_H_INCLUIDO
#define LED_H_INCLUIDO


// ----------------------------------------------------------
// ----------------------------------------------------------
void esperar (long tiempo) {
  delay (tiempo);
}

// ----------------------------------------------------------
// ----------------------------------------------------------
class LED {
private:
  int numeroLED;
  bool encendido;
public:

  // .........................................................
  // .........................................................
  LED (int numero)
	: numeroLED (numero), encendido(false)
  {
	pinMode(numeroLED, OUTPUT);
	apagar ();
  }

  // .........................................................
  // .........................................................
  // Enciende el led de la ESP
  void encender () {
	digitalWrite(numeroLED, HIGH); 
	encendido = true;
  }
  void encenderr () {
    digitalWrite(numeroLED, HIGH); 
    encendido = true;
    while(encendido = true){
      encendido = true;
    }
	
  }

  // .........................................................
  // .........................................................
  // Apaga el led de la ESP
  void apagar () {
	  digitalWrite(numeroLED, LOW);
	  encendido = false;
  }

  // .........................................................
  // .........................................................
  // Cambia el estado del led de la ESP
  void alternar () {
	if (encendido) {
	  apagar();
	} else {
	  encender ();
	}
  } // ()

  // .........................................................
  // .........................................................
  // Enciende el led de la ESP durante [N] tiempo
  void brillar (long tiempo) {
	encender ();
	esperar(tiempo); 
	apagar ();
  }
}; // class

// ----------------------------------------------------------
// ----------------------------------------------------------
// ----------------------------------------------------------
// ----------------------------------------------------------
#endif
