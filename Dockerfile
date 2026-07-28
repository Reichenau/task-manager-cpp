FROM gcc:13 AS builder
WORKDIR /app

RUN apt-get update && apt-get install cmake -y
COPY CMakeLists.txt .
COPY src/ src/
COPY include/ include/
COPY tests/ tests/
RUN cmake -S . -B build -G "Unix Makefiles"
RUN cmake --build build

CMD [ "./build/task_manager_test" ]
