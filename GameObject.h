/**
 * @file GameObject.h
 * @brief Klasa bazowa dla wszystkich obiektów gry.
 */
#pragma once
/**
 * @class GameObject
 * @brief Klaza bazowa dla innych typów obiektów.
 */
class GameObject {
private:
	/** 
	* @brief Unikalny identyfikator obiektu gry. 
	*/
	int id;
	/** 
	*@brief Licznik do generowania ID dla nowych obiektów. 
	*/
	static int nextId; 

public:
	/**
	 * @brief Konstruktor, przypisuje automatycznie ID dla nowo stworzonego obiektu.
	 */
	GameObject();
	/**
	 * @brief Wirtualny destruktor.
	 */
	virtual ~GameObject();
	/**
	* @brief Zwraca unikalny identyfikator obiektu.
	* @return ID obiektu.
	*/
	int getId() const;


};
