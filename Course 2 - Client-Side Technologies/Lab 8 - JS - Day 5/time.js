//PARENT//

//1
class Clock{
    hours;
    minutes;
    seconds; 
    #intervalId;

    //2:a
    constructor(initialTime){
        //2:b
        let parts = initialTime.split(":");
        this.hours = parseInt(parts[0]);
        this.minutes = parseInt(parts[1]);
        this.seconds = parseInt(parts[2]);
    }

    //3
    static formatTime(hours, minutes, seconds){
        const pad = (num) => String(num).padStart(2, '0');
        return `${pad(hours)}:${pad(minutes)}:${pad(seconds)}`;
    }

    //4
    #tick(){
        this.seconds++;

        if(this.seconds >= 60){
            this.seconds = 0;
            this.minutes++;
        }
        
        if(this.minutes >= 60){
            this.minutes = 0;
            this.hours++;
        }

        if(this.hours >= 24){
            this.hours = 0;
        }

        // console.clear();
        console.log(this.getTime());
    }

    //5:a
    start(){
        this.#intervalId = setInterval(() => {
            this.#tick();
        }, 1000);
    }

    //5:b
    stop(){
        clearInterval(this.#intervalId);
    }

    //5:c
    getTime(){
        return Clock.formatTime(this.hours, this.minutes, this.seconds);
    }

}

//CHILD//

//1
class AlarmClock extends Clock{
    //2
    #alarmTime;

    #alarmIntervalId;
    
    //3
    constructor(initialTime, alarmTime, alarmMessage){
        super(initialTime);
        this.#alarmTime = alarmTime;
        this.alarmMessage = alarmMessage;
    }
    
    //4
    #checkAlarm(){
        if(this.getTime() === this.#alarmTime){
            this.stop();
            return true;
        }
        return false;   
    }

    //5:a
    start() {
        super.start();
        this.#alarmIntervalId = setInterval(() => {
            if(this.#checkAlarm()){
                console.log(this.alarmMessage);
                clearInterval(this.#alarmIntervalId);
            }
        }, 1000);
    }

    //5:b
    setAlarmTime(alarmTime){
        this.#alarmTime = alarmTime;
    }

    getAlarmTime(){
        return this.#alarmTime;
    }

    stop(){
        super.stop();
        clearInterval(this.#alarmIntervalId);
    }
}