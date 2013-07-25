namespace ego {
  class Scrivener {	
    SchedulerType alg;
    long int clock = 0; //clock of alg 1
    long int clock2 = 0; //for lackof a better name, clock of alg 2
    long int runTime = 0;
    long int numJobs = 0;
    long double act = 0; //Average Completion Time
    long double throughput = 0; //Jobs per second
    long double util = 0; //time doing useful stuffs
    

    long int clockTime() {
      if (alg == SchedulerType.EXPONENTIAL) {
        return clock;
    }
        return clock2;
    }

    long double calAct() {
      act = runTime / numJobs;//get runtime from node
      return act;
    }

    long double calThroughput() {//get info from node
      throughput = numJobs / runTime;//per second so divide time by 1k?
      return throughput;
    }

    long int calUtil() {
      long double scale = 100.01;
      util = (useTime / runTime)*scale;//display as percentage and round to nearest hundredth, figure out how to get use time. possibly count everytime it's pushed?
      return util;
    }

    void iterJobs() { //iterates the job counter, i guess call whenever a new job is added to the queue
      numJobs++;
    }
		
    void iterRunTime() { //iterates the runtime counter
      runTime++;
    }

    void initialize() {
      clock = 0;
      clock2 = 0;
      runTime = 0;
      numJobs = 0;
      act = 0;
      throughput = 0;
      util = 0;
    }

    void printData(){
      calAct();
      calThroughput();
      calUtil();
    }
  }
}
