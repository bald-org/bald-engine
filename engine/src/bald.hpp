//
// Created by blinku on 06.05.19.
//

#pragma once

/**
 * This header must be included in every application that wants to use Bald Engine.
 */

// Core include

#include "core/core.hpp"

// Includes

#include "core/app/application.hpp"
#include "core/app/entry_point.hpp"
#include "core/app/layer.hpp"
#include "core/app/layer_stack.hpp"

#include "core/controllers/camera_2d_controller.hpp"

#include "core/debug/logger/log_manager.hpp"

#include "core/events/event.hpp"
#include "core/events/event_bus.hpp"
#include "core/events/key_events.hpp"
#include "core/events/layer_events.hpp"
#include "core/events/mouse_events.hpp"
#include "core/events/window_events.hpp"

#include "core/graphics/rendering/sprite.hpp"
#include "core/graphics/rendering/buffers/vertex_array.hpp"
#include "core/graphics/rendering/buffers/vertex_buffer.hpp"
#include "core/graphics/rendering/buffers/index_buffer.hpp"
#include "core/graphics/rendering/buffers/vertex_buffer_layout.hpp"
#include "core/graphics/rendering/rendering_device/renderer_2d.hpp"
#include "core/graphics/rendering/shaders/shader.hpp"
#include "core/graphics/rendering/textures/texture.hpp"

#include "core/input/input_manager.hpp"
#include "core/input/key_codes.hpp"

// GLM
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

// ImGui
#include "imgui.h"