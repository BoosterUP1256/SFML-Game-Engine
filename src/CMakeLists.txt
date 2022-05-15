target_sources(${PROJECT_NAME}
        PRIVATE
            Core.hpp Core.cpp
            Scene.hpp Scene.cpp
            Scene_Test.hpp Scene_Test.cpp
            Scene_Test2.hpp
            Action.hpp Action.cpp
            Entity.hpp Entity.cpp
            EntityManager.hpp EntityManager.cpp
            Vec2.hpp Vec2.cpp
            Animation.hpp Animation.cpp
            Components.hpp
            #main.cpp
            animTest.cpp
        )
        