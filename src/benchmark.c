/*
Seashell :A fast and simple UNIX shell in C

benchmark.c : benchmark multithread utility

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "../include/benchmark.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define ITERATIONS 10000000

// thread function to calculate Flops
void *threadFunctionFlop(void *arg){
  int i;
  double a=5;
  // convert string argument to long
  long iterations=strtol((char*)arg,NULL,0);
  for(i = 0; i < iterations; i++){
    a=a+a;
  }
  return NULL;
}

void flops(int numberOfThreads){

  clock_t start, end;
  double cpu_time_used;
  int i;
  long double a=5;
  pthread_t th[10];// array of threads

  long iterations=ITERATIONS/numberOfThreads;
  char iterationStr[20];
  //printf(iterationStr, 20, "%lu",iterations);

  printf("\nFind FLOPS for %d threads",numberOfThreads);
  start = clock();

  for(i=0;i<numberOfThreads;i++){
    pthread_create(&th[i],NULL,threadFunctionFlop,iterationStr);
    pthread_join(th[i], NULL);
  }
  
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("\nTime: %f s\n",cpu_time_used);
  double Flops=(ITERATIONS)/(double)(cpu_time_used);
  double gFlops=(double)Flops/1000000000;// Calculate Giga Flops Formula: F lops * 10raised to (-9).

  printf("GFLOPS : %f\n",gFlops);
}