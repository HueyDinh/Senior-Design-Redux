#ifndef __INCLUDE_GENERICCONTROLTEMPLATE
#define __INCLUDE_GENERICCONTROLTEMPLATE

#include <cstdint>
#include <array>

typedef float (*InputFunctionPointer) (void);

template<std::size_t input_dimension>
class ControllerInputs {

    public:

        static constexpr std::size_t INPUT_DIMENSION {input_dimension};

        ControllerInputs(std::array<InputFunctionPointer, input_dimension> function_pointer_array):
            function_pointer_array{function_pointer_array}
        {};

        void set_pointer(InputFunctionPointer function_pointer, std::size_t index) {
            function_pointer_array[index] = function_pointer;
        };

        float read_single_input(std::size_t index) {
            return function_pointer_array[index]();
        };

        std::array<float, input_dimension> read_all() {

            std::array<float, input_dimension> return_values {};

            for (int i = 0; i < input_dimension; i++) {
                return_values[i] = read_single_input(i);
            };

            return return_values;
        };
    
    private:

        std::array<InputFunctionPointer, input_dimension> function_pointer_array;

};

template<std::size_t input_dimension>
class InputFunctionProvider {
    public:
        virtual std::array<InputFunctionPointer, input_dimension> generate_input_function_pointers() = 0;
};

typedef void (*OutputFunctionPointer) (float);

template <std::size_t output_dimension>
class ControllerOutputs {

    public:

        ControllerOutputs(std::array<OutputFunctionPointer, output_dimension> function_pointer_array):
            function_pointer_array{function_pointer_array}
        {};

        static constexpr std::size_t OUTPUT_DIMENSION {output_dimension};

        void set_pointer(OutputFunctionPointer function_pointer, std::size_t index) {
            function_pointer_array[index] = function_pointer;
        };

        void write_single_output(std::size_t index, float value) {
            function_pointer_array[index](value);
        };

        void write_all(std::array<float, output_dimension> values) {

            for (int i = 0; i < output_dimension; i++) {
                write_single_output(i, values[i]);
            }

        }
    
    private:

        std::array<OutputFunctionPointer, output_dimension> function_pointer_array;

};

template<std::size_t output_dimension>
class OuputFunctionProvider {
    public:
        virtual std::array<OutputFunctionPointer, output_dimension> generate_output_function_pointers() = 0;
};

template <std::size_t input_dimension, std::size_t output_dimension>
class Controller {

    public:

        typedef std::array<float, output_dimension> (*TransformFunction) (std::array<float, input_dimension>);

        Controller(ControllerInputs<input_dimension>* input, ControllerOutputs<output_dimension>* output):
            input{input},
            output{output}
        {};

        virtual void update() = 0;

    protected:

        ControllerInputs<input_dimension>* input;
        ControllerOutputs<output_dimension>* output;

};

#endif /* __INCLUDE_GENERICCONTROLTEMPLATE */
