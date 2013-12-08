#pragma once

#include "gfx_gl.h"

class Cubes_GL_BindlessIndirect : public Cubes
{
public:
    Cubes_GL_BindlessIndirect();
    virtual ~Cubes_GL_BindlessIndirect();

    virtual bool init() override;

    virtual bool begin(void* hwnd, GfxSwapChain* swap_chain, GfxFrameBuffer* frame_buffer) override;
    virtual void end(GfxSwapChain* swap_chain) override;

    virtual void draw(Matrix* transforms, int count) override;

private:
    struct Vertex
    {
        Vec3 pos;
        Vec3 color;
    };

    struct Command
    {
        DrawElementsIndirectCommand draw;
        GLuint                      reserved; 
        BindlessPtrNV               indexBuffer;
        BindlessPtrNV               vertexBuffers[2];
    };

    GLuint m_ibs[CUBES_COUNT];
    GLuint64 m_ib_addrs[CUBES_COUNT];
    GLsizeiptr m_ib_sizes[CUBES_COUNT];
    GLuint m_vbs[CUBES_COUNT];
    GLuint64 m_vbo_addrs[CUBES_COUNT];
    GLsizeiptr m_vbo_sizes[CUBES_COUNT];
    GLuint m_vs;
    GLuint m_fs;
    GLuint m_prog;


    GLuint m_transform_buffer;
    void *m_transform_ptr;

    Command m_commands[CUBES_COUNT];
    GLuint m_cmd_buffer;
    void *m_cmd_ptr;
};