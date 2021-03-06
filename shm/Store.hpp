#pragma once
#include <iostream>

#include "Cargo.hpp"
#include "Observer.hpp"
#include "Player.hpp"

class Store : public Observer {
public:
    enum class Response {
        done,
        lack_of_money,
        lack_of_cargo,
        lack_of_space
    };

    // override from Observer
    void nextDay() override;

    Response Buy(Cargo* cargo, size_t amount, Player* player);
    Response Sell(Cargo* cargo, size_t amount, Player* player);

    friend std::ostream& operator<<(std::ostream& out, const Store& store);

private:
    std::vector<std::shared_ptr<Cargo>> _cargo;

    Cargo* findCargo(Cargo* cargo) const;
    void generateDefaultCargo();
};
