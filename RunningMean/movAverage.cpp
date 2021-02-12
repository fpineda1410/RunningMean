#include "movAverage.h" //cambiar "" por <> si hay problemas
// inicia las variables del sensor
void movingAvg::begin()
{
    m_readings = new int[m_interval];
}

// agrega la nuevamedicion y prosigue con la otra ventana
int movingAvg::reading(int newReading)
{
    // agrega nuevo puntos de datos hasta que el array este lleno
    if (m_nbrReadings < m_interval)
    {
        ++m_nbrReadings;
        m_sum = m_sum + newReading;
    }
    // cambio de ventana
    else
    {
        m_sum = m_sum - m_readings[m_next] + newReading;
    }

    m_readings[m_next] = newReading;
    if (++m_next >= m_interval) m_next = 0;
    return (m_sum + m_nbrReadings / 2) / m_nbrReadings;
}

// retornar movimiento de promedios actual
int movingAvg::getAvg()
{
    return (m_sum + m_nbrReadings / 2) / m_nbrReadings;
}

// comando reset
void movingAvg::reset()
{
    m_nbrReadings = 0;
    m_sum = 0;
    m_next = 0;
}