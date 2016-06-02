#include "InputManager.h"
#include <SFML\Window.hpp>

sf::Vector2i InputManager::_mousePos = sf::Vector2i();

bool InputManager::_cursorLocked = false;

bool InputManager::_leftMouseButton = false;
bool InputManager::_prevLeftMouseButton = false;
bool InputManager::_upKey = false;
bool InputManager::_prevUpKey = false;
bool InputManager::_downKey = false;
bool InputManager::_prevDownKey = false;
bool InputManager::_leftKey = false;
bool InputManager::_prevLeftKey = false;
bool InputManager::_rightKey = false;
bool InputManager::_prevRightKey = false;

bool InputManager::_wKey = false;
bool InputManager::_prevWKey = false;
bool InputManager::_aKey = false;
bool InputManager::_prevAKey = false;
bool InputManager::_sKey = false;
bool InputManager::_prevSKey = false;
bool InputManager::_dKey = false;
bool InputManager::_prevDKey = false;
bool InputManager::_shiftKey = false;
bool InputManager::_prevShiftKey = false;
bool InputManager::_ctrlKey = false;
bool InputManager::_prevCtrlKey = false;

bool InputManager::_prevSpaceKey = false;
bool InputManager::_spaceKey = false;

sf::Window* InputManager::_window;
float InputManager::_aspectRatio = 0.0f;
sf::Vector2u InputManager::_windowSize = sf::Vector2u();

void InputManager::Init(sf::Window* window)
{
	_window = window;
	_windowSize = _window->getSize();
	_aspectRatio = (float)_windowSize.x / (float)_windowSize.y;
}

void InputManager::Update()
{
	_prevLeftMouseButton = _leftMouseButton;
	_leftMouseButton = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
	_mousePos = sf::Mouse::getPosition(*_window);

	bool insideWindow = _mousePos.x > 0 && _mousePos.x < _windowSize.x && _mousePos.y > 0 && _mousePos.y < _windowSize.y;
	if (_leftMouseButton && (insideWindow || _cursorLocked))
	{
		sf::Mouse::setPosition(sf::Vector2i(_windowSize.x / 2, _windowSize.y / 2), *_window);
		if (!_cursorLocked)
		{
			_mousePos = sf::Mouse::getPosition(*_window);
			_cursorLocked = true;
		}
		_window->setMouseCursorVisible(false);
	}
	else
	{
		_cursorLocked = false;
		_window->setMouseCursorVisible(true);
	}

	_prevDownKey = _downKey;
	_downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	_prevUpKey = _upKey;
	_upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	_prevLeftKey = _leftKey;
	_leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	_prevRightKey = _rightKey;
	_rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

	_prevWKey = _wKey;
	_wKey = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	_prevAKey = _aKey;
	_aKey = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	_prevSKey = _sKey;
	_sKey = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	_prevDKey = _dKey;
	_dKey = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	_prevShiftKey = _shiftKey;
	_shiftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
	_prevCtrlKey = _ctrlKey;
	_ctrlKey = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);

	_prevSpaceKey = _spaceKey;
	_spaceKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

glm::vec2 InputManager::GetMouseCoords()
{
	glm::vec2 ret = glm::vec2();
	ret.x = (((float)_mousePos.x / (float)_windowSize.x) * 2.0f - 1.0f) * _aspectRatio;
	ret.y = -(((float)_mousePos.y / (float)_windowSize.y) * 2.0f - 1.0f);
	return ret;
}
bool InputManager::leftMouseButton(bool prev) { if (prev) return _prevLeftMouseButton; else return _leftMouseButton; }
bool InputManager::cursorLocked() { return _cursorLocked; }

bool InputManager::upKey(bool prev) { if (prev) return _prevUpKey; else return _upKey; }
bool InputManager::downKey(bool prev) { if (prev) return _prevDownKey; else return _downKey; }
bool InputManager::leftKey(bool prev) { if (prev) return _prevLeftKey; else return _leftKey; };
bool InputManager::rightKey(bool prev) { if (prev) return _prevRightKey; else return _rightKey; };

bool InputManager::wKey(bool prev) { if (prev) return _prevWKey; else return _wKey; }
bool InputManager::aKey(bool prev) { if (prev) return _prevAKey; else return _aKey; }
bool InputManager::sKey(bool prev) { if (prev) return _prevSKey; else return _sKey; }
bool InputManager::dKey(bool prev) { if (prev) return _prevDKey; else return _dKey; }
bool InputManager::shiftKey(bool prev) { if (prev) return _prevShiftKey; else return _shiftKey; }
bool InputManager::ctrlKey(bool prev) { if (prev) return _prevCtrlKey; else return _ctrlKey; }
bool InputManager::spaceKey(bool prev) { if (prev) return _prevSpaceKey; else return _spaceKey; }

