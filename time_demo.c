/**
 * FileName: time_demo.c 
 * sh# gcc time_demo.c -o time_demo -lrt
 */
 
#include <stdint.h> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
 
uint64_t max_count;
uint64_t local_cpu_hz;
 
uint64_t consume_time() 
{
    uint64_t i = 0;
    uint64_t c = 0xABCDEFFEDCBAAF;
    for (; i < max_count * 1000000; i ++)
        c |= i;
    for (; i < max_count * 1500000; i ++)
        c |= i;
    for (; i < max_count * 3000000; i ++)
        c |= i;
    return i;
}
 
uint64_t get_cpu_hz(uint64_t *local_cpu_hz)
{
    FILE *fp;
    char cpuinfo[128];
    memset(cpuinfo, 0, sizeof(cpuinfo));
     
    fp = popen("cat /proc/cpuinfo|grep \"cpu MHz\"|sed -e 's/.*:[^0-9]//'","r");
    if (fp == NULL) {
        printf("Open /proc/cpuinfo failed.\n");
        return -1;
    }
    if (fgets(cpuinfo, 128, fp) == NULL) {
        printf("Read cpu frequency failed.\n");
        fclose(fp);
        return -1;
    }
    *local_cpu_hz = (uint64_t)(atof(cpuinfo) * 1000000);
    pclose(fp);
    return 0;
}
 
  
uint64_t get_rdtsc() 
{
    uint64_t a, d;
  
    __asm__ volatile("rdtsc" : "=a" (a), "=d" (d));
  
    return a | (d << 32);
}
  
void time_calc_time() 
{
    time_t t1, t2;
  
    time(&t1);
    consume_time();
    time(&t2);
  
    printf("time() : %.2f s\n", (double)(t2 - t1));
}
  
void clock_calc_time() 
{
    clock_t c1 = clock();
    consume_time();
    clock_t c2 = clock();
    printf("clock() : %.2f s\n", (double) (c2 - c1) / (double) CLOCKS_PER_SEC);
}
  
void gettimeofday_calc_time() 
{
    struct timeval t1, t2;
    gettimeofday(&t1, NULL);
    consume_time();
    gettimeofday(&t2, NULL);
 
    printf("gettimeofday() : %.2f s\n", (double) (t2.tv_sec - t1.tv_sec) + 
                                        (t2.tv_usec - t1.tv_usec) / 1000000.0);
}
  
void rdtsc_calc_time() 
{
    uint64_t t1, t2;
    t1 = get_rdtsc();
    consume_time();
    t2 = get_rdtsc();
  
    printf("rdtsc() : %.2f s\n", (double) (t2 - t1) / local_cpu_hz);
}
  
void clock_gettime_calc_time() {
    struct timespec t1, t2;
    clock_gettime(CLOCK_REALTIME, &t1);
    consume_time();
    clock_gettime(CLOCK_REALTIME, &t2);
  
    printf("clock_gettime() : %.2f s\n", (double) (t2.tv_sec - t1.tv_sec) + 
                            (double) (t2.tv_nsec - t1.tv_nsec) / 1000000000.0);
}
  
int main(int argc, char *argv[])
{
    if (argc > 1) {
        sscanf(argv[1], "%li", &max_count);
	printf("%s",argv[1]);
    }
 
    if (max_count <= 0)
        max_count = 100;
     
    if (get_cpu_hz(&local_cpu_hz) == -1)
        return (-1);
  
    time_calc_time();
    clock_calc_time();
    gettimeofday_calc_time();
    rdtsc_calc_time();
    clock_gettime_calc_time();
  
    return (0);
}
