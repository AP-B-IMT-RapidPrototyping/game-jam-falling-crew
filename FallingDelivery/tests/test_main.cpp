#include <catch2/catch_test_macros.hpp>
#include "Objects.h"
#include "Pakketje.h"
#include "Player.h"
//----------------------object-------------------------------
TEST_CASE("sanity check object", "[Setup]") {
    game::Objects o = game::Objects();

    REQUIRE_NOTHROW(o.GetPosition());
}

TEST_CASE("Object", "[Object][spawnposition][x]") {
    game::Objects object = game::Objects();
    SECTION("positie") {
        SECTION("X") {
            SECTION("Groterdan 0") {
                REQUIRE(object.GetPosition().x>0);
            }
            SECTION("kleinerdan 800") {
                REQUIRE(object.GetPosition().x<800);
            }
        }
    }
}
//----------------------player-------------------------------
TEST_CASE("sanity check player", "[Setup]") {
    game::Player p = game::Player("assets/Skydiver.png");

    REQUIRE_NOTHROW(p.GetPosition());
}

TEST_CASE("Player", "[Player][spawnposition][x]") {
    game::Player player = game::Player("assets/Skydiver.png");
    SECTION("positie") {
        SECTION("X") {
            SECTION("Groterdan 0") {
                REQUIRE(player.GetPosition().x>0);
            }
            SECTION("kleinerdan 800") {
                REQUIRE(player.GetPosition().x<800);
            }
        }
    }
}
//----------------------pakketje-------------------------------
TEST_CASE("sanity check pakketje", "[Setup]") {
    game::Pakketje p = game::Pakketje("assets/pakketje.png");

    REQUIRE_NOTHROW(p.GetPosition());
}

TEST_CASE("Pakketje", "[Pakketje][spawnposition][x]") {
    game::Pakketje pakketje = game::Pakketje("assets/pakketje.png");
    SECTION("positie") {
        SECTION("X") {
            SECTION("Groterdan 0") {
                REQUIRE(pakketje.GetPosition().x>0);
            }
            SECTION("kleinerdan 800") {
                REQUIRE(pakketje.GetPosition().x<800);
            }
        }
    }
}
