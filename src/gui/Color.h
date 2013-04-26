#ifndef COLOR_H_
#define COLOR_H_

#include <iostream>

class Color{
    public:
	Color(float r, float g, float b, float a = 1.f);
	
	inline float& red() {return m_red;}
	inline float& green() {return m_green;}
	inline float& blue() {return m_blue;}
	inline float& alpha() {return m_alpha;}

	inline float red() const{return m_red;}
	inline float green() const{return m_green;}
	inline float blue() const{return m_blue;}
	inline float alpha() const{return m_alpha;}
    protected:
	float m_red, m_green, m_blue, m_alpha;
};

class HSLColor{
    public:
	HSLColor(float h, float s, float l, float a = 1.f);
	
	inline float& hue() {return m_hue;}
	inline float& saturation() {return m_saturation;}
	inline float& lightness() {return m_lightness;}
	inline float& alpha() {return m_alpha;}

	inline float hue() const {return m_hue;}
	inline float saturation() const {return m_saturation;}
	inline float lightness() const {return m_lightness;}
	inline float alpha() const {return m_alpha;}
	
	void fromColor(const Color& color);
	Color toColor() const;
	
    protected:
	float m_hue, m_saturation, m_lightness, m_alpha;
};

HSLColor RGB2HSL(const Color& color);

Color HSL2RGB(const HSLColor& color);

std::ostream& operator<< (std::ostream& out, const Color& color);
std::ostream& operator<< (std::ostream& out, const HSLColor& color);

#endif

