**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

> NEW: process is about to be created.
> READY: process is loaded into the main memory and is ready to run, but waiting to get the CPU time for execution.
> RUN: process is chosen to be executed by CPU and the code within the process is executed by one of the CPU cores that is available.
> BLOCKED: process waits in the main memory when it doesn't have access or something it needs, becoming ready after IO operations are completed.
> SUSPENDED READY: process was in ready state, but was swapped out of main memory and placed into external storage by the scheduler. Transitions back to ready when the process is brought back into main memory.
> SUSPENDED WAIT: process that was performing IO operation and lack of main memory causes the process to move to secondary memory. When work is complete, it can go to suspend ready.
> COMPLETED: process is killed.

**2. What is a zombie process?**

> When the child executes first, but the parent doesn't clean up after it, the child becomes a "zombie process" - a process that has finished executing, but as of yet, has not been cleaned up.


**3. How does a zombie process get created? How does one get destroyed?**

> A zombie process is created when the child dies, but the parent process hasn't called wait() to reap the zombie process. This could be a very short amount of time, or a longer amount of time.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
> Compiled languages have fast execution because they are converted directly into machine code that the processer can execute. They are also more efficient because of this. The developer has more control over memory management and CPU usage.


