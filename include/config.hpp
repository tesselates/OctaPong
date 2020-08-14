#pragma once

struct Config {
    static constexpr double paddle_length = 50;
    static constexpr double paddle_thinckness = 10;
    static constexpr double view_width = 500;
    static constexpr double view_height = 500;
    static constexpr double distance_buffer = 25;
    static constexpr int update_rate = 1;  // The update rate in ms
    static constexpr double frequency = 100/update_rate;  //  the frequence in cs-1
    static constexpr double sin45 = 0.70;
};
