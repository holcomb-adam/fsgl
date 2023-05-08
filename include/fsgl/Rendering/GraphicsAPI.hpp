#pragma once

// --- GLM ---
#include <glm/vec4.hpp>

// --- Standard ---
#include <memory>



namespace fsgl
{
    // FSGL Forward Declarations
    class VertexArray;



    /// @brief Abstract interface of an underlying graphics API. The GraphicsHandle provides FSGL a
    ///        medium for communicating with the underlying graphics API like OpenGL, Vulkan, SDL2,
    ///        etc.
    class GraphicsAPI
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - MEMBER TYPES --------------------------------------------------------------

        /// @todo Need to support more API's like Vulkan, DirectX, Software fallback (custom or
        ///       SDL2), etc.
        /// @brief An enum representing the underlying graphics API
        enum class API
        {
            // No graphics API
            None,

            // GPU graphics APIs
            OpenGL,

            // Software graphics APIs
        };



    public:
        /// @brief 
        /// @param graphics_api 
        static void init(API graphics_api);

        static const std::unique_ptr<GraphicsAPI>& get();

        static API activeAPI();



    public:
        GraphicsAPI(API api_type);

        virtual ~GraphicsAPI() = default;


        ////////////////////////////////////////////////////////////////////////////////
        // - VIRTUALS ------------------------------------------------------------------

        virtual void init() = 0;
        virtual void setClearColor(const glm::vec4& color) const = 0;
        virtual void clear() const = 0;
        virtual void viewport(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h) const = 0;
        virtual void draw(const std::shared_ptr<VertexArray>& vao) const = 0;
    };
}
