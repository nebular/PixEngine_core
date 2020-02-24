//
//  Geometry2D.hpp
//  PixFu
//
//  Created by rodo on 11/02/2020.
//  Copyright © 2020 rodo. All rights reserved.
//

#ifndef Geometry2D_hpp
#define Geometry2D_hpp

#include "Drawable.hpp"
#include "Font.hpp"

namespace rgl {

class Canvas2D {
	
	Drawable *pTarget;
	Font *pFont;

public:
	
	Canvas2D(Drawable *target, Font *defaultFont = nullptr);
	
	void setPixel(int32_t x, int32_t y, Pixel p);
	
	void clear(Pixel color = Pixel(0, 0, 0, 0));
	
	void blank();
	
	void drawString(int32_t x, int32_t y, std::string sText, rgl::Pixel col,
					uint32_t scale = 1);
	
	void
	drawWireFrameModel(const std::vector<std::pair<float, float>> &vecModelCoordinates, float x,
					   float y, float r, float s, std::vector<rgl::Pixel> col);
	
	void drawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, Pixel p,
				  uint32_t pattern = 0xFFFFFFFF);
	
	void drawCircle(int32_t x, int32_t y, int32_t radius, Pixel p, uint8_t mask = 0xff);
	
	void fillCircle(int32_t x, int32_t y, int32_t radius, Pixel p);
	
	void drawRect(int32_t x, int32_t y, int32_t w, int32_t h, Pixel p);
	
	void fillRect(int32_t x, int32_t y, int32_t w, int32_t h, Pixel p);
	
	void drawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3,
					  Pixel p);
	
	void fillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3,
					  Pixel p);
	
	void drawSprite(int32_t x, int32_t y, rgl::Drawable *drawable, uint32_t sampleWidth=0);

	int width();
	
	int height();
	
	bool clearDirty();
	
};

inline void Canvas2D::setPixel(int32_t x, int32_t y, Pixel p) { pTarget->setPixel(x,y,p); }

inline int Canvas2D::width() { return pTarget->width; }

inline int Canvas2D::height() { return pTarget->height; }

}


#endif /* Geometry2D_hpp */
