#ifndef AUDIOHANDLER_HPP_
# define AUDIOHANDLER_HPP_

# include <unistd.h>
# include <iostream>
# include <SFML/Audio.hpp>

/**
 *  SFX
 */

# define FOOTSTEPS ("media/audio/sounds/FootSteps.wav")
# define SWORDSLASH ("media/audio/sounds/SwordSlash.wav")

/**
 *  BG Musics
 */

# define INTRO ("media/audio/musics/Intro.ogg")
# define MENU ("media/audio/musics/Menu.ogg")
# define MDUNGEON ("media/audio/musics/Dungeon.ogg")
# define BOSSBATTLE ("media/audio/musics/BossBattle.ogg")
# define GAMEOVER ("media/audio/musics/GameOver.ogg")

class AudioHandler {
private:
	bool is_music_loaded_;
	sf::Music music_;

	bool is_sound_loaded_;
	sf::SoundBuffer buffer_;
	sf::Sound sound_;

public:
	AudioHandler();
	~AudioHandler();

	int LoadMusic(std::string path);
	void SetMusicVolume(float volume);
	int PlayMusic();
	int PauseMusic();
	int StopMusic();
	int LoadSound(std::string path);
	void SetSoundVolume(float volume);
	int PlaySound(bool isRepeatable);
	int StopSound();
};

#endif /* !AUDIOHANDLER_HPP_ */
