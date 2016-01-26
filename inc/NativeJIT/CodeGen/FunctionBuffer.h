#pragma once

#include "NativeJIT/CodeGen/X64CodeGenerator.h"     // Inherits from X64CodeGenerator.

#ifdef NATIVEJIT_PLATFORM_WINDOWS
#include "NativeJIT/CodeGen/Windows/FunctionBuffer.h"
#else
#include "NativeJIT/CodeGen/POSIX/FunctionBuffer.h"
#endif


namespace NativeJIT
{
    class FunctionSpecification;

    // TODO:
    // http://stackoverflow.com/questions/3119929/forwarding-all-constructors-in-c0x
    // https://alfps.wordpress.com/2010/06/05/cppx-w4-no-warnings-part-ii-disabling-msvc-sillywarnings/
    // Using directive for constructors does not work in VS2013.
    // using FunctionSpecificationBase::FunctionSpecificationBase;
    class FunctionBuffer : public FunctionBufferBase
    {
    public:
        // Sets up a code buffer with specified capacity and registers a
        // callback to facilitate stack unwinding on exception. See the
        // CodeBuffer constructor for more details on the allocator.
        FunctionBuffer(Allocators::IAllocator& codeAllocator, unsigned capacity)
            : FunctionBufferBase(codeAllocator, capacity)
        {
        }
    };
}
