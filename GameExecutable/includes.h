#pragma once
#include <SFML/Graphics.hpp> 
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <math.h>
#include <list>
using namespace sf;

#define RAND(min,max) min+rand()%(max-(min)+1)

#define TILESIZE 32
#define AMOUNTWOLVES 23
#define AMOUNTSKELKETONES 50
#define AMOUNTSLIME 60
#define AMOUNTPOTIONS 5
#define AMOUNTDESERTPOTIONS 7
#define AMOUNTSAFEZONES 13

#define DESERTPASSIVEDAMAGE 0.004f
#define DESERTENDURANCERESTORATION 0.014f

//координаты тайлов из тайлсета игрока
// Knight (ожившие доспехи3,k=])
#define PlStandingRight new Frames[1]{ {Coord(0, 120), 120, 120} }
#define PlWalkingRight new Frames[6]{ {Coord(120, 120), 120,120}, {Coord(240, 120), 120,120}, {Coord(360, 120), 120,120}, {Coord(480, 120), 120,120}, {Coord(600, 120), 120,120}, {Coord(720, 120), 120,120}}
#define PlBlockingRight new Frames[1]{ {Coord(0, 360), 120,120} }
#define PlAtackingRight new Frames[3]{ {Coord(120, 360), 120,120}, {Coord(240, 360), 120,120}, {Coord(360, 360), 120,120} }
#define PlDyingRight new Frames[8] {{Coord(0, 600), 120, 120},{Coord(120, 600), 120, 120},{Coord(240, 600), 120, 120},{Coord(360, 600), 120, 120},{Coord(480, 600), 120, 120},{Coord(600, 600), 120, 120},{Coord(720, 600), 120, 120},{Coord(720, 600), 120, 120}}
#define PlDamagingRight new Frames[2] {{Coord(0, 600), 120, 120},{Coord(120, 600), 120, 120}}

#define PlStandingLeft new Frames[1]{ {Coord(0, 0), 120, 120} }
#define PlWalkingLeft new Frames[6]{ {Coord(120, 0), 120,120}, {Coord(240, 0), 120,120}, {Coord(360, 0), 120,120}, {Coord(480, 0), 120,120}, {Coord(600, 0), 120,120}, {Coord(720, 0), 120,120} }
#define PlBlockingLeft new Frames[1]{ {Coord(0, 240), 120,120} }
#define PlAtackingLeft new Frames[3]{ {Coord(120, 240), 120,120}, {Coord(240, 240), 120,120}, {Coord(360, 240), 120,120} }
#define PlDyingLeft new Frames[8] {{Coord(0, 480), 120, 120},{Coord(120, 480), 120, 120},{Coord(240, 480), 120, 120},{Coord(360, 480), 120, 120},{Coord(480, 480), 120, 120},{Coord(600, 480), 120, 120},{Coord(720, 480), 120, 120},{Coord(720, 480), 120, 120}}
#define PlDamagingLeft new Frames[2] {{Coord(0, 480), 120, 120},{Coord(120, 480), 120, 120}}

// Wolf
#define WolfStandingRight new Frames[1]{{Coord(27, 25), 63, 76}}
#define WolfWalkingRight new Frames[6]{ {Coord(27, 165), 56, 94}, {Coord(122, 165), 56, 105}, {Coord(231, 165), 56, 107}, {Coord(343, 165), 56, 107}, {Coord(461, 165), 56, 95}, {Coord(564, 165), 56, 94}}
#define WolfAtackingRight new Frames[3]{ {Coord(26, 226), 86, 90}, {Coord(119, 226), 86, 81}, {Coord(200, 226), 86, 90}}
#define WolfDyingRight    new Frames[7]{ {Coord(25, 471), 91, 63}, {Coord(99, 471), 91, 50}, {Coord(154, 471), 91, 60}, {Coord(221, 471), 90, 93}, {Coord(318, 471), 90, 93}, {Coord(418, 471), 90, 93}, {Coord(520, 471), 90, 93}}
#define WolfDamagingRight new Frames[4]{ {Coord(25, 471), 91, 63},{Coord(25, 471), 91, 63}, {Coord(99, 471), 91, 50}, {Coord(154, 471), 91, 60}}

#define WolfStandingLeft new Frames[1]{{Coord(103, 25), 63, -76}}
#define WolfWalkingLeft new Frames[6]{ {Coord(121, 165), 56, -94}, {Coord(227, 165), 56, -105}, {Coord(338, 165), 56, -107}, {Coord(450, 165), 56, -107}, {Coord(556, 165), 56, -95}, {Coord(658, 165), 56, -94}}
#define WolfAtackingLeft new Frames[3]{ {Coord(116, 226), 86, -90}, {Coord(200, 226), 86, -81}, {Coord(290, 226), 86, -90}}
#define WolfDyingLeft     new Frames[7]{ {Coord(88, 471), 91, -63}, {Coord(149, 471), 91, -50}, {Coord(214, 471), 91, -60}, {Coord(314, 471), 90, -93}, {Coord(411, 471), 90, -93}, {Coord(511, 471), 90, -93}, {Coord(613, 471), 90, -93}}
#define WolfDamagingLeft  new Frames[4]{ {Coord(88, 471), 91, -63},{Coord(88, 471), 91, -63}, {Coord(149, 471), 91, -50}, {Coord(214, 471), 91, -60}}

// Skeleton
#define SkeletonStandingRight new Frames[2]{{Coord(0, 115),58, 81}, {Coord(300, 115), 58, 81}}
#define SkeletonWalkingRight  new Frames[4]{{Coord(0, 223), 56, 81}, {Coord(150, 223), 56, 81}, {Coord(300, 223), 56, 81}, {Coord(450, 223), 56, 81}}
#define SkeletonAtackingRight new Frames[7]{{Coord(0, 0), 58, 81}, {Coord(142, 0), 58, 81}, {Coord(292, 0), 58, 81}, {Coord(442, 0), 58, 81}, {Coord(597, 0), 58, 81}, {Coord(758, 0), 58, 81}, {Coord(908, 0), 58, 81}}
#define SkeletonDyingRight    new Frames[4]{{Coord(0, 60), 58, 81}, {Coord(146, 60), 58, 81}, {Coord(294, 60), 58, 81}, {Coord(442, 60), 58, 81}}
#define SkeletonDamagingRight new Frames[3]{{Coord(1, 170), 54, 81}, {Coord(141, 170), 54, 81}, {Coord(293, 170), 54, 81}}

#define SkeletonStandingLeft  new Frames[2]{{Coord(81, 115),58, -81}, {Coord(381, 115), 58, -81}}
#define SkeletonWalkingLeft   new Frames[4]{{Coord(81, 223), 56, -81}, {Coord(231, 223), 56, -81}, {Coord(381, 223), 56, -81}, {Coord(531, 223), 56, -81}}
#define SkeletonAtackingLeft  new Frames[7]{{Coord(81, 0), 58, -81}, {Coord(223, 0), 58, -81}, {Coord(373, 0), 58, -81}, {Coord(523, 0), 58, -81}, {Coord(678, 0), 58, -81}, {Coord(839, 0), 58, -81}, {Coord(989, 0), 58, -81}}
#define SkeletonDyingLeft     new Frames[4]{{Coord(81, 60), 58, -81}, {Coord(227, 60), 58, -81}, {Coord(375, 60), 58, -81}, {Coord(523, 60), 58, -81}}
#define SkeletonDamagingLeft  new Frames[3]{{Coord(82, 170), 54, -81}, {Coord(222, 170), 54, -81}, {Coord(374, 170), 54, -81}}

// Slime
#define SlimeStandingLeft  new Frames[4]{{Coord(1, 3), 21, 31}, {Coord(33, 3), 21, 31}, {Coord(65, 3), 21, 31}, {Coord(97, 3), 21, 31}}
#define SlimeWalkingLeft   new Frames[4]{{Coord(130, 3), 21, 31}, {Coord(162, 3), 21, 31}, {Coord(194, 3), 21, 31}, {Coord(225, 3), 21, 31}}
#define SlimeAtackingLeft  new Frames[5]{{Coord(1, 28), 21, 31}, {Coord(33, 28), 21, 31}, {Coord(65, 28), 21, 31}, {Coord(97, 28), 21, 31}, {Coord(129, 28), 21, 31}}
#define SlimeDamagingLeft  new Frames[4]{{Coord(160, 28), 21, 31}, {Coord(160, 28), 21, 31}, {Coord(193, 28), 21, 31}, {Coord(224, 28), 21, 31}}
#define SlimeDyingLeft     new Frames[5]{{Coord(1, 53), 21, 31}, {Coord(32, 53), 21, 31}, {Coord(64, 53), 21, 31}, {Coord(95, 53), 21, 31}, {Coord(128, 53), 21, 31}}

#define SlimeStandingRight new Frames[4]{{Coord(32, 3), 21, -31}, {Coord(64, 3), 21, -31}, {Coord(96, 3), 21, -31}, {Coord(128, 3), 21, -31}}   
#define SlimeWalkingRight  new Frames[4]{{Coord(161, 3), 21, -31}, {Coord(193, 3), 21, -31}, {Coord(225, 3), 21, -31}, {Coord(256, 3), 21, -31}}      
#define SlimeAtackingRight new Frames[5]{{Coord(32, 28), 21, -31}, {Coord(64, 28), 21, -31}, {Coord(96, 28), 21, -31}, {Coord(128, 28), 21,- 31}, {Coord(160, 28), 21, -31}}
#define SlimeDamagingRight new Frames[4]{{Coord(191, 28), 21, -31}, {Coord(191, 28), 21, -31}, {Coord(224, 28), 21, -31}, {Coord(255, 28), 21, -31}} 
#define SlimeDyingRight    new Frames[5]{{Coord(32, 53), 21, -31}, {Coord(63, 53), 21, -31}, {Coord(95, 53), 21, -31}, {Coord(126, 53), 21, -31}, {Coord(159, 53), 21, -31}}


enum Diraction {
  right, left, up,down, Max_Dir
};

enum State {
  standing, walking, blocking, atacking, dying, damaging
};