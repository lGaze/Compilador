#pragma once

using namespace System;

namespace CompilerCore {
	public ref class Manager
	{
	public:

		Manager();
		~Manager();

		cli::array<String^> ^ compileProgram(String ^sourceCode);
	};
}

