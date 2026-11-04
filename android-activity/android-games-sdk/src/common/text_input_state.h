#pragma once

#include <game-text-input/gametextinput.h>
#include <string>

struct OwnedGameTextInputState {
    std::string text;
    GameTextInputSpan selection = {};
    GameTextInputSpan composingRegion = {};
    uint64_t context_id = 0;

    OwnedGameTextInputState& operator=(const GameTextInputState& state) {
        if (state.text_length > 0) {
            text.assign(state.text_UTF8, state.text_length);
        } else {
            text.clear();
        }
        selection = state.selection;
        composingRegion = state.composingRegion;
        context_id = state.context_id;
        return *this;
    }

    GameTextInputState view() const {
        return {text.c_str(), static_cast<int32_t>(text.size()), selection, composingRegion, context_id};
    }
};
