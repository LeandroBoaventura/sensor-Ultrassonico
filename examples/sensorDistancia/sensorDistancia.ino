#include "pulsoUltraSonico.h"

/**
 * @brief  DEFINICAO DO PINO DE TRIGER DO SENSOR ULTRASSONICO
 */
#define PIN_TRIG 8

/**
 * @brief DEFINICAO DO PINO DE ECHO DO SENSOR ULTRASSONICO
 */
#define PIN_ECHO 7

/**
 * @brief INSTANCIA DA CLASSE DO SENSOR ULTRASSONICO
 */
pulsoUltraSonico Sensor(PIN_TRIG, PIN_ECHO);

/**
 * @brief FUNCAO PRINCIPAL DE CONFIGURACAO
 */
void setup(void)
{
  Serial.begin(9600);
}

/**
 * @brief FUNCAO PRINCIPAL DO FIMWARE
 */
void loop(void)
{
  float distancia = Sensor.getDistancia();

  Serial.print("distancia ");
  Serial.println(distancia);

  delay(500);
}
