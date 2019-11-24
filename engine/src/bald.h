//
// Created by blinku on 06.05.19.
//

#pragma once

/**
 * This header must be included in every application that wants to use Bald Engine.
 */

// Core include

#include "core/core.h"

// Includes

#include "core/app/application.h"
#include "core/app/entry_point.h"
#include "core/app/layer.h"
#include "core/app/layer_stack.h"

#include "core/debug/logger/log_manager.h"

#include "core/events/event.h"
#include "core/events/event_manager.h"
#include "core/events/key_events.h"
#include "core/events/layer_events.h"
#include "core/events/mouse_events.h"
#include "core/events/window_events.h"

#include "core/graphics/rendering/camera_2d.h"
#include "core/graphics/rendering/sprite.h"
#include "core/graphics/rendering/buffers/vertex_array.h"
#include "core/graphics/rendering/buffers/vertex_buffer.h"
#include "core/graphics/rendering/buffers/index_buffer.h"
#include "core/graphics/rendering/buffers/vertex_buffer_layout.h"
#include "core/graphics/rendering/rendering_device/renderer_2d.h"
#include "core/graphics/rendering/shaders/shader.h"
#include "core/graphics/rendering/textures/texture.h"

#include "core/input/input_manager.h"
#include "core/input/key_codes.h"

// GLM
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"