//
//  ZoomList.cpp
//  Fractal
//
//  Created by Tyler Coleman on 3/16/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <stdio.h>
#include "ZoomList.h"

using namespace std;

ZoomList::ZoomList(int width, int height) : m_width(width), m_height(height) {}

void ZoomList::add(const Zoom &zoom) {
    zooms.push_back(zoom);
    
    // Calculate coordinates of center of new zoom frame based on distance from center (0,0) pixel.
    // Apply scaling.
    m_xCenter += (zoom.x - m_width / 2) * m_scale;
    m_yCenter += -(zoom.y - m_height / 2) * m_scale;
    
    m_scale *= zoom.scale;
}

pair<double, double> ZoomList::doZoom(int x, int y) {
    
    double xFractal = (x - m_width / 2) * m_scale + m_xCenter;
    double yFractal = (y - m_height / 2) * m_scale + m_yCenter;
    
    return pair<double, double>(xFractal, yFractal);
}
