/*

	1RM formulas

*/


#define NAN -3222;  
extern float lbs2kgs(float weight);
extern float kgs2lbs(float weight);
extern float oneRMbrzycki(float weight, int reps);
extern float oneRMeppley(float weight, int reps);
extern float oneRMlanders(float weight, int reps);
extern float oneRMlombardi(float weight, int reps);


double npower(double const base, int const n)
{
    if (n < 0)
         return npower(1/base, -n);
    else if (n == 0) return 1.0;
    else if (n == 1) return base;
    else if (n % 2) return base*npower(base*base, n/2);
    else return npower(base*base, n/2);
}

double nroot(double const base, int const n)
{
    if (n == 1) return base;
    else if (n <= 0 || base < 0) return -32222;
    else {
        double delta, x = base/n;
        do {
            delta = (base/npower(x,n-1)-x)/n;
            x += delta;
        } while (fabs(delta) >= 1e-8);
        return x;
    }
}

typedef struct oneRMpercentiles
{
    int _95;
    int _90;
    int _85;
    int _80;
    int _75;
    int _70;
    int _65;
    int _60;
    int _55;
    int _50;
} oneRMpercentiles;

typedef struct oneRMrecord
{
	char exercise[20];
    float weight;
	int reps;
    int max;
	float brzycki;
	float eppley;
	float landers;
	float lombardi;
    struct oneRMpercentiles percentiles;
} oneRMrecord;



float lbs2kgs(float weight)
{
	return weight/2.2;
}

float kgs2lbs(float weight)
{
	return weight*2.2;
}

float oneRMbrzycki(float weight, int reps)
{
	return weight / ( 1.0278 - 0.0278 * reps );
}

float oneRMeppley(float weight, int reps)
{
	return weight * (1 + 0.0333*reps);
}

float oneRMlanders(float weight, int reps)
{
        return (100 * weight)/(101.3- 2.67123 * reps);
}

float oneRMlombardi(float weight, int reps)
{
        return weight * nroot(reps,10);
}

void calc1RMbrzycki(char exercise[20], float weight, int reps, struct oneRMrecord *onermRec)
{
    strcpy(onermRec->exercise,exercise);
    onermRec->weight = weight;
    onermRec->reps = reps;
    onermRec->brzycki = oneRMbrzycki(weight,reps);
    onermRec->eppley = oneRMeppley(weight,reps);
    onermRec->landers = oneRMlanders(weight,reps);
    onermRec->lombardi = oneRMlombardi(weight,reps);
    onermRec->max = (int) onermRec->brzycki;
    onermRec->percentiles._95 = (int) (.95 * onermRec->max);
    onermRec->percentiles._90 = (int) (.90 * onermRec->max);
    onermRec->percentiles._85 = (int) (.85 * onermRec->max);
    onermRec->percentiles._80 = (int) (.80 * onermRec->max);
    onermRec->percentiles._75 = (int) (.75 * onermRec->max);
    onermRec->percentiles._70 = (int) (.70 * onermRec->max);
    onermRec->percentiles._65 = (int) (.65 * onermRec->max);
    onermRec->percentiles._60 = (int) (.60 * onermRec->max);
    onermRec->percentiles._55 = (int) (.55 * onermRec->max);
    onermRec->percentiles._50 = (int) (.50 * onermRec->max);
}

void calc1RMweighted(char exercise[20], float weight, int reps, struct oneRMrecord *onermRec)
{
    strcpy(onermRec->exercise,exercise);
    onermRec->weight = weight;
    onermRec->reps = reps;
    onermRec->brzycki = oneRMbrzycki(weight,reps);
    onermRec->eppley = oneRMeppley(weight,reps);
    onermRec->landers = oneRMlanders(weight,reps);
    onermRec->lombardi = oneRMlombardi(weight,reps);
    onermRec->max = (int) (onermRec->brzycki *.66 + onermRec->eppley * .11 + onermRec->landers * .12 + onermRec->lombardi * .11);
    onermRec->percentiles._95 = (int) (.95 * onermRec->max);
    onermRec->percentiles._90 = (int) (.90 * onermRec->max);
    onermRec->percentiles._85 = (int) (.85 * onermRec->max);
    onermRec->percentiles._80 = (int) (.80 * onermRec->max);
    onermRec->percentiles._75 = (int) (.75 * onermRec->max);
    onermRec->percentiles._70 = (int) (.70 * onermRec->max);
    onermRec->percentiles._65 = (int) (.65 * onermRec->max);
    onermRec->percentiles._60 = (int) (.60 * onermRec->max);
    onermRec->percentiles._55 = (int) (.55 * onermRec->max);
    onermRec->percentiles._50 = (int) (.50 * onermRec->max);
}

