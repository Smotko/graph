#ifndef TEMPLATEGAME_H_
#define TEMPLATEGAME_H_

#include "gameplay.h"
#include "Logger.h"

#define NUM_DAYS 7
#define NUM_HOURS 24

using namespace gameplay;

/**
 * Main game class.
 */
class Graph: public Game
{
public:

    /**
     * Constructor.
     */
    Graph();

    /**
     * @see Game::keyEvent
     */
	void keyEvent(Keyboard::KeyEvent evt, int key);
	
    /**
     * @see Game::touchEvent
     */
    void touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex);

protected:

    /**
     * @see Game::initialize
     */
    void initialize();

    /**
     * @see Game::finalize
     */
    void finalize();

    /**
     * @see Game::update
     */
    void update(float elapsedTime);

    /**
     * @see Game::render
     */
    void render(float elapsedTime);

private:

    Matrix _projectionMatrix;
    Matrix _viewMatrix;
    Matrix _viewProjectionMatrix;
    float data[NUM_DAYS][NUM_HOURS];// = {{2758, 2063, 1175, 554, 428, 324, 271, 188, 456, 1087, 2089, 2164, 2525, 1957, 2213, 2463, 2679, 2470, 2039, 2005, 2569, 3200, 4009, 3876}, {2449, 1332, 426, 180, 106, 132, 149, 146, 273, 989, 1638, 1598, 2475, 1831, 2267, 2419, 2170, 1971, 2394, 2277, 2754, 2465, 3293, 4719}, {3356, 1815, 1028, 240, 143, 140, 104, 267, 329, 1537, 2584, 2525, 2101, 2108, 2199, 2082, 2139, 2433, 2270, 1832, 2338, 2384, 3579, 4011}, {3010, 1810, 785, 238, 170, 149, 151, 193, 465, 1114, 2536, 2556, 2209, 1996, 2408, 2544, 2478, 2539, 2500, 1962, 2229, 2417, 3115, 3962}, {3198, 2263, 1019, 331, 120, 113, 109, 178, 313, 1050, 2185, 2338, 2019, 2101, 1608, 2033, 2208, 2357, 2504, 1873, 1875, 1675, 1989, 2112}, {2302, 1763, 577, 282, 124, 77, 64, 100, 237, 610, 1237, 1820, 1876, 2101, 1871, 2005, 1720, 2210, 2184, 2250, 2347, 2294, 2608, 2751}, {1803, 825, 480, 241, 119, 71, 58, 69, 133, 505, 1336, 2122, 1782, 1975, 2109, 1796, 1971, 2140, 2910, 2248, 2191, 2326, 3578, 3295}};
    Node* nodes[NUM_DAYS][NUM_HOURS];
    Scene* _scene;
    Model* mDays;
    Font* _font;

    /**
     * Draws the scene each frame.
     */
    bool drawScene(Node* node);

    void initBlocks();
    void initLabels();
};

#endif
