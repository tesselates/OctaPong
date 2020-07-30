#pragma once

struct Config {
    static constexpr double paddle_length = 50;
    static constexpr double paddle_thinckness = 10;
    static constexpr double view_width = 500;
    static constexpr double view_height = 500;
    static constexpr double distance_buffer = 75;
    static constexpr int update_rate = 100;
    static constexpr double update_rate2 = 100;
    static constexpr double frequency = 1/(update_rate2/1000);
};
