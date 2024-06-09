

#include "Character.hpp"

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        delete this->Materia[i];
    }
}

Character::Character(Character const &character)
{
    std::cout << "Character Copy Constructor Called" << std::endl;
    *this = character;
}
Character &Character::operator=(Character const &character)
{
    std::cout << "Character Assignation Operator Called" << std::endl;
    if (this != &character)
    {
        this->Name = character.Name;
        for (int i = 0; i < 4; i++)
        {
            if(character.Materia[i] != NULL)
                this->Materia[i] = character.Materia[i]->clone();
            else
                this->Materia[i] = NULL;
        } 
    }
    return (*this);
}

Character::Character(std::string const &name) : Name(name)
{
    for (int i = 0; i < 4; i++)
    {
        Materia[i] = NULL;
    }
}
std::string const &Character::getName() const
{
    return (Name);
}

void Character::equip(AMateria *materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (Materia[i] == NULL)
        {
            Materia[i] = materia;
            break;
        }
    }
}
void Character::unequip(int idx)
{
    if(this->Materia[idx] != NULL)
    {
        delete this->Materia[idx];
        this->Materia[idx] = NULL;
    }
    else
    {
        std::cout << "Materia is already unequiped" << std::endl;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && Materia[idx] != NULL)
        Materia[idx]->use(target);
    else  
        std::cout << "Materia is not equiped" << std::endl;
}