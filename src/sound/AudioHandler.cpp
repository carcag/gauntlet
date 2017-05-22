#include "AudioHandler.hpp"

AudioHandler::AudioHandler() {
	is_music_loaded_ = false;
	is_sound_loaded_ = false;
}

AudioHandler::~AudioHandler() {
}

int		AudioHandler::LoadMusic(std::string path) {
	if (!music_.openFromFile(path))
		return -1;
	is_music_loaded_ = true;
	return 0;
}

void		AudioHandler::SetMusicVolume(float volume) {
	if (is_music_loaded_ == true)
		music_.setVolume(volume);
}

int		AudioHandler::PlayMusic() {
	if (is_music_loaded_ == false)
		return -1;
	music_.setLoop(true);
	music_.play();
	return 0;
}

int		AudioHandler::PauseMusic() {
	if (is_music_loaded_ == false)
		return -1;
	music_.pause();
	return 0;
}

int		AudioHandler::StopMusic() {
	if (is_music_loaded_ == false)
		return -1;
	music_.stop();
	return 0;
}

int		AudioHandler::LoadSound(std::string path) {
	if (!buffer_.loadFromFile(path))
		return -1;
	is_sound_loaded_ = true;
	return 0;
}

void		AudioHandler::SetSoundVolume(float volume) {
	if (is_sound_loaded_ == true)
		sound_.setVolume(volume);
}

int		AudioHandler::PlaySound(bool isRepeatable) {
	int			duration;
	sf::Time		time;

	time = buffer_.getDuration();
	duration = (int)(time.asSeconds() + 0.5);
	sound_.setBuffer(buffer_);
	if (isRepeatable)
		sound_.setLoop(true);
	sound_.play();
	if (!isRepeatable) {
			sleep(duration);
			sound_.stop();
		}
	return 0;
}

int		AudioHandler::StopSound() {
	if (is_sound_loaded_ == false)
		return -1;
	sound_.stop();
	return 0;
}
