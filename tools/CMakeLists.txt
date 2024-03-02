set(APP emojiMapGenerator)

add_executable(${APP}
		emojiMapGenerator.cpp
)

target_link_libraries(${APP}
        PRIVATE Qt6::Widgets
)
