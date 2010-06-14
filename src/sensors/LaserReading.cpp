#include "LaserReading.h"


using namespace std;

LaserReading::LaserReading(const vector<double>& _phi, const vector<double>& _rho, double _time, const string& _name, const string& _robot):
    AbstractReading(_time, _name, _robot),
    m_maxRange(80),
    m_phi(_phi),
    m_rho(_rho)
{
    m_remission.reserve(m_rho.size());
    m_laserPose.x = 0;
    m_laserPose.y = 0;
    m_laserPose.theta = 0;
    computeLocalCartesian();
    m_worldCartesian = m_cartesian;
}

LaserReading::~LaserReading(){

}

void LaserReading::setRemission(const vector<double>& _remi){
    if(_remi.size() == m_phi.size())
	m_remission = _remi;
}

void LaserReading::setLaserPose(const OrientedPoint2D& _pose){
    m_laserPose = _pose;
    computeWorldCartesian();
}

void LaserReading::computeWorldCartesian(){
    m_worldCartesian.resize(m_phi.size());
    for(unsigned int i = 0; i < m_phi.size(); i++){
	if(m_rho[i]<m_maxRange){
	    m_worldCartesian[i].x = cos(m_phi[i] + m_laserPose.theta)*m_rho[i] + m_laserPose.x;
	    m_worldCartesian[i].y = sin(m_phi[i] + m_laserPose.theta)*m_rho[i] + m_laserPose.y;
	} else {
	    m_worldCartesian[i].x = cos(m_phi[i] + m_laserPose.theta)*m_maxRange + m_laserPose.x;
	    m_worldCartesian[i].y = sin(m_phi[i] + m_laserPose.theta)*m_maxRange + m_laserPose.y;
/*	    m_worldCartesian[i].x = 0;
	    m_worldCartesian[i].y = 0;*/
	}
    }
}

void LaserReading::computeLocalCartesian(){
    m_cartesian.resize(m_phi.size());
    for(unsigned int i = 0; i < m_phi.size(); i++){
	if(m_rho[i]<m_maxRange){
	    m_cartesian[i].x = cos(m_phi[i])*m_rho[i];
	    m_cartesian[i].y = sin(m_phi[i])*m_rho[i];
	} else {
	    m_cartesian[i].x = cos(m_phi[i] + m_laserPose.theta)*m_maxRange + m_laserPose.x;
	    m_cartesian[i].y = sin(m_phi[i] + m_laserPose.theta)*m_maxRange + m_laserPose.y;
	}
    }
}

AbstractReading* LaserReading::clone() const{
    return new LaserReading(*this);
}
