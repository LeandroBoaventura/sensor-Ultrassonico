#ifndef _PULSO_ULTRASONICO_H
#define _PULSO_ULTRASONICO_H

/**
 * @file pulsoUltraSonico.h
 * @author Leandro Boaventura (lnboaventura@gmail.com)
 * @brief BIBLIOTECA PARA CONTROLE DE LEITURA DO SENSOR ULTRASSONICO
 * @version 0.1
 * @date 2023-06-15
 * @copyright Copyright (c) 2023 \b Leandro_Boaventura 
 */

#include <Arduino.h>

/**
 * @brief tempo de delay enquanto o Trig esta ligado
 */
#define TEMPO_DO_PULSO 10

/**
 * @brief velocidade do som em microsegundos para o calculo da distancia
 */
#define VELOCIDADE_SOM_MICRO_S 0.000340

/**
 * @brief paramentro de centimetros para calculo da distancia 
 */
#define UNIDADE_METRO_CM 100

class pulsoUltraSonico
{
public:
    pulsoUltraSonico(uint8_t pinTrig, uint8_t pinEcho);
    void disparoPulsoTrig(uint8_t tempoDoPulso);
    float calculoDaDistancia(float tempoUs, uint8_t unidade);
    float getDistancia(void);

private:
    /**
     * @brief variavel privada para o pino do trig
     */
    uint8_t _pinTrig = NULL;

    /**
     * @brief variavel privada para o pino do echo
     */
    uint8_t _pinEcho = NULL;
};

#endif
