#ifndef GAUNTLET_HPP_
# define GAUNTLET_HPP_

# include <chrono>

# define GAME_UPDATE_PER_SECOND (60)

typedef std::chrono::high_resolution_clock::time_point t_time_point;
typedef std::chrono::high_resolution_clock t_clock;
typedef std::chrono::duration<double, std::milli> t_dur;

#endif /* !GAUNTLET_HPP_ */
