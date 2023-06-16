#include "pulsoUltraSonico.h"

/**
 * @brief funcao para declarar os pinos usado no arduino.
 * @param pinTrig varialvel para o pino do trig, declarando como saida e desligado em primeiro momento.
 * @param pinEcho variavel para o pino de echo, declarando como entrada.
 */
pulsoUltraSonico::pulsoUltraSonico(uint8_t pinTrig, uint8_t pinEcho)
{
    pinMode(pinTrig, OUTPUT);
    digitalWrite(pinTrig, LOW);
    pinMode(pinEcho, INPUT);
    _pinTrig = pinTrig;
    _pinEcho = pinEcho;
}

/**
 * @brief funcao para assionar o disparo do trig.
 * @param tempoDoPulso variavel que determinar quanto tempo o pulso do trig vai estar ligado.
 */
void pulsoUltraSonico::disparoPulsoTrig(uint8_t tempoDoPulso)
{
    digitalWrite(_pinTrig, HIGH);
    delay(tempoDoPulso);
    digitalWrite(_pinTrig, LOW);
}

/**
 * @brief funcao que caulcula a distancia percorrida em cm.
 * @param tempoUs variavel da funcao que recebe o tempo do Echo.
 * @param unidade varialvel da funcao que recebe o valor da unidade de cm 100.
 * @return \c float com o valor da distancia
 */
float pulsoUltraSonico::calculoDaDistancia(float tempoUs, uint8_t unidade)
{
    return (((tempoUs * VELOCIDADE_SOM_MICRO_S) / 2) * unidade);
}

/**
 * @brief funcao conjuta que chama o disparo de trig, faz a leitura do sinal do Echo e logo apos chama a 
 *        funcao calculoDaDistancia.
 * @return \c float com o resultado do calculo da distancia.
 */
float pulsoUltraSonico::getDistancia(void)
{
    disparoPulsoTrig(TEMPO_DO_PULSO);
    float tempoEcho = pulseIn(_pinEcho, HIGH);
    pulseIn(_pinEcho, HIGH);

    float distancia = calculoDaDistancia(tempoEcho, UNIDADE_METRO_CM);

    return distancia;
}
