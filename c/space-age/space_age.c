#include "space_age.h"

/* Mercury: orbital period 0.2408467 Earth years
Venus: orbital period 0.61519726 Earth years
Earth: orbital period 1.0 Earth years, 365.25 Earth days, or 31557600 seconds
Mars: orbital period 1.8808158 Earth years
Jupiter: orbital period 11.862615 Earth years
Saturn: orbital period 29.447498 Earth years
Uranus: orbital period 84.016846 Earth years
Neptune: orbital period 164.79132 Earth years*/

float age(planet_t planet, int64_t seconds)
{
    switch (planet)
    {
    case MERCURY:
        return (seconds / 31557600 / 0.2408467);
        break;
    case VENUS:
        return (seconds / 31557600 / 0.61519726);
        break;
    case EARTH:
        return (seconds / 31557600);
        break;
    case MARS:
        return (seconds / 31557600 / 1.8808158);
        break;
    case JUPITER:
        return (seconds / 31557600 / 11.862615);
        break;
    case SATURN:
        return (seconds / 31557600 / 29.447498);
        break;
    case URANUS:
        return (seconds / 31557600 / 84.016846);
        break;
    case NEPTUNE:
        return (seconds / 31557600 / 164.79132);
        break;
    default:
        return -1;
        break;
    }
}
