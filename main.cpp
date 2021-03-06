//
//  main.cpp
//  Fractal
//
//  Created by Tyler Coleman on 3/5/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <iostream>
#include "FractalCreator.h"
#include "Screen.h"
#include "RGB.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    FractalCreator fractalCreator(Screen::SCREEN_WIDTH, Screen::SCREEN_HEIGHT);
    
    fractalCreator.addZoom(Zoom(300, 300, 0.6));
    
    // Need to ensure a start range (0.0) and an end range (1.0) are specified. All other ranges
    // should end between these two.
    fractalCreator.addRange(0.0, RGB(0,0,0));
    fractalCreator.addRange(0.05, RGB(255,0,0));
    fractalCreator.addRange(0.15, RGB(175,100,200));
    fractalCreator.addRange(1.0, RGB(150,225,175));
    
    fractalCreator.run("test.bmp");
    
    cout << "Finished" << endl;
    
    return 0;
}
