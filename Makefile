CC := g++

RM := rm -f

TARGET := gauntlet

INCLUDE := -Iinclude/ -Iinclude/irrlicht# -ISFML-2.2/include

LIB := lib/

SRC := src/

CORE := core/

INTRO := intro/

MENU := menu/

PAUSEGAME := pause_game/

WONGAME := won_game/

GAMEOVER := game_over/

LEVEL1 := level1/

CXXFLAGS += -std=c++11 $(INCLUDE)

LDFLAGS += -L$(LIB) -lIrrlicht -lGL -lXxf86vm -lXext -lX11 -lXcursor# -LSFML-2.2/lib -lsfml-audio -lsfml-system

SOURCES :=	$(SRC)main.cpp\
			$(SRC)$(CORE)EventReceiver.cpp\
			$(SRC)$(CORE)GameEngine.cpp\
			$(SRC)$(CORE)GameState.cpp\
			$(SRC)$(CORE)StateManager.cpp\
			$(SRC)$(CORE)HUD.cpp\
			$(SRC)$(CORE)LifeBar.cpp\
			$(SRC)$(CORE)Entity.cpp \
			$(SRC)$(CORE)PowerUp.cpp \
			$(SRC)$(CORE)SpeedPowerUp.cpp \
			$(SRC)$(CORE)LifePowerUp.cpp \
			$(SRC)$(CORE)AtkSpeedPowerUp.cpp \
			$(SRC)$(CORE)Character.cpp \
			$(SRC)$(CORE)DestructibleObject.cpp \
			$(SRC)$(CORE)PlayerCharacter.cpp \
			$(SRC)$(CORE)NonPlayerCharacter.cpp \
			$(SRC)$(CORE)ProjectileManager.cpp \
			$(SRC)$(CORE)AI.cpp\
			$(SRC)$(INTRO)IntroState.cpp\
			$(SRC)$(INTRO)IntroEventHandler.cpp \
			$(SRC)$(INTRO)IntroUpdateHandler.cpp \
			$(SRC)$(INTRO)IntroRenderHandler.cpp \
			$(SRC)$(MENU)MenuState.cpp \
			$(SRC)$(MENU)MenuEventHandler.cpp \
			$(SRC)$(MENU)MenuUpdateHandler.cpp \
			$(SRC)$(MENU)MenuRenderHandler.cpp \
			$(SRC)$(PAUSEGAME)PauseGameState.cpp \
			$(SRC)$(PAUSEGAME)PauseGameEventHandler.cpp \
			$(SRC)$(PAUSEGAME)PauseGameUpdateHandler.cpp \
			$(SRC)$(PAUSEGAME)PauseGameRenderHandler.cpp \
			$(SRC)$(WONGAME)WonGameState.cpp \
			$(SRC)$(WONGAME)WonGameEventHandler.cpp \
			$(SRC)$(WONGAME)WonGameUpdateHandler.cpp \
			$(SRC)$(WONGAME)WonGameRenderHandler.cpp \
			$(SRC)$(GAMEOVER)GameOverState.cpp \
			$(SRC)$(GAMEOVER)GameOverEventHandler.cpp \
			$(SRC)$(GAMEOVER)GameOverUpdateHandler.cpp \
			$(SRC)$(GAMEOVER)GameOverRenderHandler.cpp \
			$(SRC)$(LEVEL1)Level1State.cpp \
			$(SRC)$(LEVEL1)Level1EventHandler.cpp \
			$(SRC)$(LEVEL1)Level1UpdateHandler.cpp \
			$(SRC)$(LEVEL1)Level1RenderHandler.cpp# \
			#$(SRC)sound/AudioHandler.cpp

OBJECTS := $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

install:
	@echo "Installing..."
	@echo "Done!"

.PHONY: all clean fclean re
