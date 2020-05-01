/*
 * MyUltrasonic.h
 *
 * Library for MyUltrasonic Ranging Module in a minimalist way
 *
 * created 3 Apr 2014
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 23 Jan 2017
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 04 Mar 2017
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 15 May 2017
 * by Eliot Lim    (github: @eliotlim)
 * modified 10 Jun 2018
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 *
 * Released into the MIT License.
 */

#ifndef MyUltrasonic_h
#define MyUltrasonic_h

/*
 * Values of divisors
 */
#define CM 28
#define INC 71

class MyUltrasonic {
  public:
    MyUltrasonic(uint8_t sigPin) : MyUltrasonic(sigPin, sigPin) {};
    MyUltrasonic(uint8_t trigPin, uint8_t echoPin, unsigned long timeOut = 20000UL);
    unsigned int read(uint8_t und = CM);
    unsigned int distanceRead(uint8_t und = CM) __attribute__ ((deprecated ("This method is deprecated, use read() instead.")));
    void setTimeout(unsigned long timeOut) {timeout = timeOut;}
    int get_average(int samples_count, int samples_interval);
    bool is_connected();
    int samples[10];
    int samples_average;
    int samples_sum;
    int distance;

  private:
    void shift_samples(int samples_count);
    uint8_t trig;
    uint8_t echo;
    boolean threePins = false;
    unsigned long previousMicros;
    unsigned long timeout;
    unsigned int timing();
};

#endif // MyUltrasonic_h
