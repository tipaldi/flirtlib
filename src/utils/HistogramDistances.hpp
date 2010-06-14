#define PSEUDOZERO 0.0000001

#include <iostream>

template<class Numeric>
double HistogramDistance<Numeric>::distance(const std::vector< std::vector<Numeric> >& first, const std::vector< std::vector<Numeric> >& last) const{
    if (first.size() != last.size()) return 10e16;
    double accumulator = 0.;
    for (unsigned int i = 0; i < first.size(); i++){
	accumulator += distance(first[i], last[i]);
    }
    return accumulator;
}

/// Euclidean
template<class Numeric>
double EuclideanDistance<Numeric>::distance(const std::vector< std::vector<Numeric> >& first, const std::vector< std::vector<Numeric> >& last) const{
    if (first.size() != last.size()) return 10e16;
    double accumulator = 0.;
    for (unsigned int i = 0; i < first.size(); i++){
	accumulator += distance(first[i], last[i]) * distance(first[i], last[i]);
    }
    return sqrt(accumulator);
}

template<class Numeric>
double EuclideanDistance<Numeric>::distance(const std::vector<Numeric>& first, const std::vector<Numeric>& last) const{
    if (first.size() != last.size()) return 10e16;
    double accumulator = 0.;
    for (unsigned int i = 0; i < first.size(); i++){
	accumulator += (first[i] - last[i])*(first[i] - last[i]);
    }
    return sqrt(accumulator * 0.5);
}

/// Chi2
template<class Numeric>
double Chi2Distance<Numeric>::distance(const std::vector<Numeric>& first, const std::vector<Numeric>& last) const{
    if (first.size() != last.size()) return 10e16;
    double accumulator = 0.;
    for (unsigned int i = 0; i < first.size(); i++){
	double p = last[i] == 0 ? PSEUDOZERO : last[i];
	double q = first[i] == 0 ? PSEUDOZERO : first[i];
	accumulator += (q - p)*(q - p)/q;
    }
    return accumulator;
}

/// Symmetric Chi2
template<class Numeric>
double SymmetricChi2Distance<Numeric>::distance(const std::vector<Numeric>& first, const std::vector<Numeric>& last) const{
    if (first.size() != last.size()) return 10e16;
    double accumulator = 0.;
    for (unsigned int i = 0; i < first.size(); i++){
	double p = last[i] == 0 ? PSEUDOZERO : last[i];
	double q = first[i] == 0 ? PSEUDOZERO : first[i];
	accumulator += (q - p)*(q - p)/(q + p);    
    }
    return 0.5 * accumulator; //TOCHECK Some books says to use 2 other 0.5
}

///Batthacharyya
template<class Numeric>
double BatthacharyyaDistance<Numeric>::distance(const std::vector< std::vector<Numeric> >& first, const std::vector< std::vector<Numeric> >& last) const{
    if (first.size() != last.size()) return 10e16;
    double accumulator = 0.;
    for (unsigned int i = 0; i < first.size(); i++){
	double current = distance(first[i], last[i]);
	accumulator += 1. - current * current;
    }
    return sqrt(1. - accumulator);
}

template<class Numeric>
double BatthacharyyaDistance<Numeric>::distance(const std::vector<Numeric>& first, const std::vector<Numeric>& last) const{
    if (first.size() != last.size()) return 10e16;
    double accumulator = 0.;
    for (unsigned int i = 0; i < first.size(); i++){
	double p = last[i];// <= 0 ? PSEUDOZERO : last[i];
	double q = first[i];// <= 0 ? PSEUDOZERO : first[i];
	accumulator += sqrt(q * p);
    }
    return sqrt(1. - accumulator);
}

///KullbackLeibler
template<class Numeric>
double KullbackLeiblerDistance<Numeric>::distance(const std::vector<Numeric>& first, const std::vector<Numeric>& last) const{
    if (first.size() != last.size()) return 10e16;
    double accumulator = 0.;
    for (unsigned int i = 0; i < first.size(); i++){
	double p = last[i] <= 0 ? PSEUDOZERO : last[i];;
	double q = first[i] <= 0 ? PSEUDOZERO : first[i];
	accumulator += p * log (p/q);
    }
    return accumulator;
}

///JensenShannon
template<class Numeric>
double JensenShannonDistance<Numeric>::distance(const std::vector<Numeric>& first, const std::vector<Numeric>& last) const{
    if (first.size() != last.size()) return 10e16;
    double accumulator = 0.;
    for (unsigned int i = 0; i < first.size(); i++){
	double p = last[i] <= 0 ? PSEUDOZERO : last[i];
	double q = first[i] <= 0 ? PSEUDOZERO : first[i];
	accumulator += p * log (2*p/(p + q)) + q * log (2*q/(p + q));
    }
    return 0.5 * accumulator / log(2);
}