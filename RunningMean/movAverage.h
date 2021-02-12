
#ifndef MOVINGAVG_H_INCLUDED
#define MOVINGAVG_H_INCLUDED

class movingAvg
{
    public:
        movingAvg(int interval)
            : m_interval(interval), m_nbrReadings(0), m_sum(0), m_next(0) {}
        void begin();
        int reading(int newReading);
        int getAvg();
        int getCount() {return m_nbrReadings;}
        void reset();
        int* getReadings() {return m_readings;}

    private:
        int m_interval;     // intervalo con la cantidad de datos
        int m_nbrReadings;  // cantidad de mediciones
        long m_sum;         // sumatoria de todas las mediciones
        int m_next;         // indice a la siguiente medicion
        int *m_readings;    // pointer de memoria para la medicion
};
#endif

//---nombre de variables para el moving average