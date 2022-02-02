#pragma once
const char index_html[] = R"rawliteral(
<!DOCTYPE html>
<html>

<head>
    <meta content="width=device-width, initial-scale=1" name="viewport" />
    <meta charset="UTF-8" />
    <link rel="manifest" href='data:application/manifest+json,{"name": "Ambient Lights", "short_name": "Ambi Lights", "description": "Smort lights", "display": "standalone"}' />

    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <title>Ambient Lights</title>
    <style>
        * {
            box-sizing: border-box;
        }

        :root {
            --pink: 154, 6, 128;
            --violet: 121, 1, 140;
            --purple: 76, 0, 112;
            --deep-purple: 22, 0, 64;
            --dark-blue: 31, 54, 61;
            --grapefruit: 255, 113, 91;
            --apple: 153, 194, 77;
            --cherry: 255, 87, 51;
            --sky: 137, 210, 220;
            --eggplant: 117, 79, 91;
            --gree: #2A3439;
            --gradient-roseanna: linear-gradient(to right, #ffafbd, #ffc3a0);
            --gradient-honey-dew: linear-gradient(to right, #43c6ac, #f8ffae);
            --gradient-vice-city: linear-gradient(to right, #3494e6, #ec6ead);
            --gradient-dusk: linear-gradient(to right, #2c3e50, #fd746c);
            --gradient-dawn: linear-gradient(to right, #f3904f, #3b4371);
            --gradient-vertical-dawn: linear-gradient(#f3904f, #3b4371);
            --gradient-love-couple: linear-gradient(to right, #3a6186, #89253e);
            --gradient-azure-pop: linear-gradient(to right, #ef32d9, #89fffd);
            --gradient-sunset: linear-gradient(to right, #0b486b, #f56217);
            --gradient-fire: linear-gradient(to right, #ff4e50, #f9d423);
            --gradient-fire-extended: linear-gradient(to right, #ff4e50, #f9d423 200%%);
            --gradient-vertical-dusk-and-night: linear-gradient(0deg, #2c3e50, #0b486b);
        }

        .card.gradient-roseanna,
        .gradient-roseanna {
            background: var(--gradient-roseanna);
        }

        .card.gradient-honey-dew,
        .gradient-honey-dew {
            background: var(--gradient-honey-dew);
        }

        .card.gradient-vice-city,
        .gradient-vice-city {
            background: var(--gradient-vice-city);
        }

        .card.gradient-dusk,
        .gradient-dusk {
            background: var(--gradient-dusk);
        }

        .card.gradient-dawn,
        .gradient-dawn {
            background: var(--gradient-dawn);
        }

        .card.gradient-vertical-dawn,
        .gradient-vertical-dawn {
            background: var(--gradient-vertical-dawn);
        }

        .card.gradient-love-couple,
        .gradient-love-couple {
            background: var(--gradient-love-couple);
        }

        .card.gradient-azure-pop,
        .gradient-azure-pop {
            background: var(--gradient-azure-pop);
        }

        .card.gradient-sunset,
        .gradient-sunset {
            background: var(--gradient-sunset);
        }

        .card.gradient-fire,
        .gradient-fire {
            background: var(--gradient-fire);
        }

        .card.gradient-fire-extended,
        .gradient-fire-extended {
            background: var(--gradient-fire-extended);
        }

        .card.gradient-vertical-dusk-and-night,
        .gradient-vertical-dusk-and-night {
            background: var(--gradient-vertical-dusk-and-night);
        }

        body {
            color: white;
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: flex-start;
            font-family: Verdana, Geneva, Tahoma, sans-serif;
            margin: 0;
            padding: 15px 30px;
            width: 100%%;
            max-width: 100vw;
            overflow-x: hidden;
            background: rgb(20, 30, 40);
            height: 100vh;
        }

        .card {
            transition: 0.2s ease;
            margin-top: 15px;
            max-width: 100%%;
            border-radius: 7px;
            padding: 25px 30px;
            width: 60vw;
            box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2);
            background: var(--gradient-vice-city);
            background-size: 100%%;
        }

        .card:hover {
            transition: 0.2s ease;
            background-size: 150%%;
        }

        .effects-container {
            transition: 0.2s ease;
            display: flex;
            justify-content: flex-start;
            margin-top: 15px;
            margin-bottom: 15px;
            max-width: 100%%;
            width: 60vw;
            background: transparent;
            transform: scaleY(1);
        }

        .card-square {
            overflow: hidden;
            transition: 200ms ease;
            border-radius: 7px;
            width: 20%%;
            padding-top: 20%%;
            position: relative;
            margin-right: 5%%;
            background-size: 100%%;
        }

        .card-square:hover {
            transition: 200ms ease;
            background-size: 150%%;
        }

        .hidden.effects-container {
            margin: 0;
            height: unset;
        }

        .hidden .card-square {
            transition: 200ms ease;
            padding-top: 0;
        }

        .card-square:last-of-type {
            margin-right: 0;
        }

        .card-square svg {
            position: absolute;
            left: 50%%;
            top: 50%%;
            transform: translate(-50%%, -50%%);
        }

        .hidden {
            transition: 200ms ease;
            overflow: hidden;
            padding: 0;
            height: 0;
            transform: scaleY(0);
            margin: 0;
        }

        .flex-justify-row {
            display: flex;
            flex-direction: row;
            justify-content: space-between;
        }

        input[type="number"],
        select {
            width: 100%%;
            padding: 12px 20px;
            margin: 8px 0;
            display: inline-block;
            border: 1px solid #ccc;
            border-radius: 4px;
        }

        input[type="submit"] {
            letter-spacing: 1.1px;
            width: 100%%;
            background-color: #4caf50;
            color: white;
            padding: 14px 20px;
            margin: 8px 0;
            margin-left: 15px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
        }

        input[type="button"] {
            letter-spacing: 1.1px;
            width: 100%%;
            background-color: #f44336;
            color: white;
            padding: 14px 20px;
            margin: 8px 0;
            margin-right: 15px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
        }

        input[type="submit"]:hover {
            background-color: #45a049;
        }

        @media (max-width: 950px) {

            .card,
            .effects-container {
                width: calc(100vw - 30px);
            }
        }

        button[data-setter] {
            outline: none;
            background: transparent;
            border: none;
            font-weight: 300;
            font-size: 18px;
            width: 25px;
            height: 30px;
            color: #2A3439;
            cursor: pointer;
        }

        button[data-setter]:hover {
            opacity: 0.5;
        }

        .fa-icons {
            width: 30px;
            height: auto;
            color: white;
        }

        .fa-icons--on {
            height: 28px;
        }

        .fa-icons--inactive {
            color: rgba(20, 30, 40, 0.85);
        }

        .fa-icons--active {
            color: white;
        }

        .dashboard-row {
            display: flex;
            justify-content: space-between;
        }

        .dashboard-col {
            display: flex;
            justify-content: center;
            align-items: center;
        }

        button {
            transition: color 50ms ease;
            outline: none;
            background: transparent;
            border: none;
            font-weight: 300;
            font-size: 18px;
            cursor: pointer;
        }

        button:active {
            color: rgb(var(--apple));
        }

        .mr-auto {
            margin-right: auto;
        }

        .card-headline {
            margin-left: 30px;
            font-size: 18px;
            font-weight: bold;
        }

        .slidecontainer {
            margin-top: 15px;
            width: 100%%;
        }

        .slider {
            transition: 200ms ease;
            -webkit-appearance: none;
            width: 100%%;
            height: 7px;
            border-radius: 5px;
            background: linear-gradient(to right, rgba(20, 30, 40, 0.3), rgba(255, 255, 255, 0.3));
            outline: none;
            opacity: 0.6;
        }

        .slider:active::-webkit-slider-thumb {
            width: 25px;
            height: 25px;
        }

        .slider:active {
            transition: 200ms ease;
            opacity: 1;
        }

        .slider::-webkit-slider-thumb {
            -webkit-appearance: none;
            appearance: none;
            width: 18px;
            height: 18px;
            border-radius: 50%%;
            background: rgba(255, 255, 255, 1);
            cursor: pointer;
        }

        .slider::-moz-range-thumb {
            width: 18px;
            height: 18px;
            border-radius: 50%%;
            background: rgba(255, 255, 255, 1);
            cursor: pointer;
        }

        svg {
            pointer-events: none;
        }
    </style>
</head>

<body>
    <div class="card gradient-fire shown">
        <div class="card-content">
            <div class="dashboard-row">
                <div class="dashboard-col effects-button">
                    <svg class="fa-icons" xmlns="http://www.w3.org/2000/svg" aria-hidden="true" focusable="false"
                        data-prefix="fas" data-icon="bed" role="img" viewBox="0 0 640 512">
                        <path fill="currentColor"
                            d="M176 256c44.11 0 80-35.89 80-80s-35.89-80-80-80-80 35.89-80 80 35.89 80 80 80zm352-128H304c-8.84 0-16 7.16-16 16v144H64V80c0-8.84-7.16-16-16-16H16C7.16 64 0 71.16 0 80v352c0 8.84 7.16 16 16 16h32c8.84 0 16-7.16 16-16v-48h512v48c0 8.84 7.16 16 16 16h32c8.84 0 16-7.16 16-16V240c0-61.86-50.14-112-112-112z" />
                    </svg>
                </div>
                <div class="dashboard-col card-headline mr-auto">Lights Bed</div>
                <div class="dashboard-col" id="lightsBedSwitch" data-controllername="bedlights">
                    <svg class="fa-icons fa-icons--on fa-icons--active" aria-hidden="true" focusable="false"
                        data-prefix="fas" data-icon="power-off" role="img" xmlns="http://www.w3.org/2000/svg"
                        viewBox="0 0 512 512">
                        <path fill="currentColor"
                            d="M400 54.1c63 45 104 118.6 104 201.9 0 136.8-110.8 247.7-247.5 248C120 504.3 8.2 393 8 256.4 7.9 173.1 48.9 99.3 111.8 54.2c11.7-8.3 28-4.8 35 7.7L162.6 90c5.9 10.5 3.1 23.8-6.6 31-41.5 30.8-68 79.6-68 134.9-.1 92.3 74.5 168.1 168 168.1 91.6 0 168.6-74.2 168-169.1-.3-51.8-24.7-101.8-68.1-134-9.7-7.2-12.4-20.5-6.5-30.9l15.8-28.1c7-12.4 23.2-16.1 34.8-7.8zM296 264V24c0-13.3-10.7-24-24-24h-32c-13.3 0-24 10.7-24 24v240c0 13.3 10.7 24 24 24h32c13.3 0 24-10.7 24-24z">
                        </path>
                    </svg>
                </div>
            </div>
            <div class="dashboard-row">
                <div class="slidecontainer">
                    <input type="range" min="0" max="255" value="200" class="slider" id="brightnessBed">
                </div>
            </div>
        </div>
    </div>
    <div class="effects-container hidden">
        <div class="effect-button card-square gradient-fire" data-effectname="fire" data-controllername="bedlights">
            <svg class="fa-icons" aria-hidden="true" focusable="false" data-prefix="fas" data-icon="fire" role="img"
                xmlns="http://www.w3.org/2000/svg" viewBox="0 0 384 512">
                <path fill="currentColor"
                    d="M216 23.86c0-23.8-30.65-32.77-44.15-13.04C48 191.85 224 200 224 288c0 35.63-29.11 64.46-64.85 63.99-35.17-.45-63.15-29.77-63.15-64.94v-85.51c0-21.7-26.47-32.23-41.43-16.5C27.8 213.16 0 261.33 0 320c0 105.87 86.13 192 192 192s192-86.13 192-192c0-170.29-168-193-168-296.14z">
                </path>
            </svg>
        </div>
        <div class="effect-button card-square gradient-honey-dew" data-effectname="strobo" data-controllername="bedlights">
            <svg class="fa-icons" aria-hidden="true" focusable="false" data-prefix="fas" data-icon="bolt" role="img"
                xmlns="http://www.w3.org/2000/svg" viewBox="0 0 320 512">
                <path fill="currentColor"
                    d="M296 160H180.6l42.6-129.8C227.2 15 215.7 0 200 0H56C44 0 33.8 8.9 32.2 20.8l-32 240C-1.7 275.2 9.5 288 24 288h118.7L96.6 482.5c-3.6 15.2 8 29.5 23.3 29.5 8.4 0 16.4-4.4 20.8-12l176-304c9.3-15.9-2.2-36-20.7-36z">
                </path>
            </svg>
        </div>
        <div class="effect-button card-square gradient-vice-city" data-effectname="rain" data-controllername="bedlights">
            <svg class="fa-icons" aria-hidden="true" focusable="false" data-prefix="fas" data-icon="cloud-showers-heavy"
                role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512">
                <path fill="currentColor"
                    d="M183.9 370.1c-7.6-4.4-17.4-1.8-21.8 6l-64 112c-4.4 7.7-1.7 17.5 6 21.8 2.5 1.4 5.2 2.1 7.9 2.1 5.5 0 10.9-2.9 13.9-8.1l64-112c4.4-7.6 1.7-17.4-6-21.8zm96 0c-7.6-4.4-17.4-1.8-21.8 6l-64 112c-4.4 7.7-1.7 17.5 6 21.8 2.5 1.4 5.2 2.1 7.9 2.1 5.5 0 10.9-2.9 13.9-8.1l64-112c4.4-7.6 1.7-17.4-6-21.8zm-192 0c-7.6-4.4-17.4-1.8-21.8 6l-64 112c-4.4 7.7-1.7 17.5 6 21.8 2.5 1.4 5.2 2.1 7.9 2.1 5.5 0 10.9-2.9 13.9-8.1l64-112c4.4-7.6 1.7-17.4-6-21.8zm384 0c-7.6-4.4-17.4-1.8-21.8 6l-64 112c-4.4 7.7-1.7 17.5 6 21.8 2.5 1.4 5.2 2.1 7.9 2.1 5.5 0 10.9-2.9 13.9-8.1l64-112c4.4-7.6 1.7-17.4-6-21.8zm-96 0c-7.6-4.4-17.4-1.8-21.8 6l-64 112c-4.4 7.7-1.7 17.5 6 21.8 2.5 1.4 5.2 2.1 7.9 2.1 5.5 0 10.9-2.9 13.9-8.1l64-112c4.4-7.6 1.7-17.4-6-21.8zM416 128c-.6 0-1.1.2-1.6.2 1.1-5.2 1.6-10.6 1.6-16.2 0-44.2-35.8-80-80-80-24.6 0-46.3 11.3-61 28.8C256.4 24.8 219.3 0 176 0 114.2 0 64 50.1 64 112c0 7.3.8 14.3 2.1 21.2C27.8 145.8 0 181.5 0 224c0 53 43 96 96 96h320c53 0 96-43 96-96s-43-96-96-96z">
                </path>
            </svg>
        </div>
    </div>
    <div class="card gradient-honey-dew shown">
        <div class="card-content">
            <div class="dashboard-row">
                <div class="dashboard-col effects-button">
                    <svg class="fa-icons" xmlns="http://www.w3.org/2000/svg" aria-hidden="true" focusable="false"
                        data-prefix="fas" data-icon="tv" role="img" viewBox="0 0 640 512">
                        <path fill="currentColor"
                            d="M592 0H48A48 48 0 0 0 0 48v320a48 48 0 0 0 48 48h240v32H112a16 16 0 0 0-16 16v32a16 16 0 0 0 16 16h416a16 16 0 0 0 16-16v-32a16 16 0 0 0-16-16H352v-32h240a48 48 0 0 0 48-48V48a48 48 0 0 0-48-48zm-16 352H64V64h512z" />
                    </svg>
                </div>
                <div class="dashboard-col card-headline mr-auto">TV Console</div>
                <div class="dashboard-col">
                    <svg data-controllername="bedlights" class="fa-icons fa-icons--on fa-icons--inactive" aria-hidden="true" focusable="false"
                        data-prefix="fas" data-icon="power-off" role="img" xmlns="http://www.w3.org/2000/svg"
                        viewBox="0 0 512 512">
                        <path fill="currentColor"
                            d="M400 54.1c63 45 104 118.6 104 201.9 0 136.8-110.8 247.7-247.5 248C120 504.3 8.2 393 8 256.4 7.9 173.1 48.9 99.3 111.8 54.2c11.7-8.3 28-4.8 35 7.7L162.6 90c5.9 10.5 3.1 23.8-6.6 31-41.5 30.8-68 79.6-68 134.9-.1 92.3 74.5 168.1 168 168.1 91.6 0 168.6-74.2 168-169.1-.3-51.8-24.7-101.8-68.1-134-9.7-7.2-12.4-20.5-6.5-30.9l15.8-28.1c7-12.4 23.2-16.1 34.8-7.8zM296 264V24c0-13.3-10.7-24-24-24h-32c-13.3 0-24 10.7-24 24v240c0 13.3 10.7 24 24 24h32c13.3 0 24-10.7 24-24z">
                        </path>
                    </svg>
                </div>
            </div>
            <div class="dashboard-row">
                <div class="slidecontainer">
                    <input type="range" min="0" max="255" value="80" class="slider" id="myRange">
                </div>
            </div>
        </div>
    </div>
    <div class="effects-container hidden">
        <div class="effect-button card-square gradient-fire" data-effectname="fire" data-controllername="tvconsole">
            <svg class="fa-icons" aria-hidden="true" focusable="false" data-prefix="fas" data-icon="fire" role="img"
                xmlns="http://www.w3.org/2000/svg" viewBox="0 0 384 512">
                <path fill="currentColor"
                    d="M216 23.86c0-23.8-30.65-32.77-44.15-13.04C48 191.85 224 200 224 288c0 35.63-29.11 64.46-64.85 63.99-35.17-.45-63.15-29.77-63.15-64.94v-85.51c0-21.7-26.47-32.23-41.43-16.5C27.8 213.16 0 261.33 0 320c0 105.87 86.13 192 192 192s192-86.13 192-192c0-170.29-168-193-168-296.14z">
                </path>
            </svg>
        </div>
        <div class="effect-button card-square gradient-honey-dew" data-effectname="strobo" data-controllername="tvconsole">
            <svg class="fa-icons" aria-hidden="true" focusable="false" data-prefix="fas" data-icon="bolt" role="img"
                xmlns="http://www.w3.org/2000/svg" viewBox="0 0 320 512">
                <path fill="currentColor"
                    d="M296 160H180.6l42.6-129.8C227.2 15 215.7 0 200 0H56C44 0 33.8 8.9 32.2 20.8l-32 240C-1.7 275.2 9.5 288 24 288h118.7L96.6 482.5c-3.6 15.2 8 29.5 23.3 29.5 8.4 0 16.4-4.4 20.8-12l176-304c9.3-15.9-2.2-36-20.7-36z">
                </path>
            </svg>
        </div>
        <div class="effect-button card-square gradient-vice-city" data-effectname="rain" data-controllername="tvconsole">
            <svg class="fa-icons" aria-hidden="true" focusable="false" data-prefix="fas" data-icon="cloud-showers-heavy"
                role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512">
                <path fill="currentColor"
                    d="M183.9 370.1c-7.6-4.4-17.4-1.8-21.8 6l-64 112c-4.4 7.7-1.7 17.5 6 21.8 2.5 1.4 5.2 2.1 7.9 2.1 5.5 0 10.9-2.9 13.9-8.1l64-112c4.4-7.6 1.7-17.4-6-21.8zm96 0c-7.6-4.4-17.4-1.8-21.8 6l-64 112c-4.4 7.7-1.7 17.5 6 21.8 2.5 1.4 5.2 2.1 7.9 2.1 5.5 0 10.9-2.9 13.9-8.1l64-112c4.4-7.6 1.7-17.4-6-21.8zm-192 0c-7.6-4.4-17.4-1.8-21.8 6l-64 112c-4.4 7.7-1.7 17.5 6 21.8 2.5 1.4 5.2 2.1 7.9 2.1 5.5 0 10.9-2.9 13.9-8.1l64-112c4.4-7.6 1.7-17.4-6-21.8zm384 0c-7.6-4.4-17.4-1.8-21.8 6l-64 112c-4.4 7.7-1.7 17.5 6 21.8 2.5 1.4 5.2 2.1 7.9 2.1 5.5 0 10.9-2.9 13.9-8.1l64-112c4.4-7.6 1.7-17.4-6-21.8zm-96 0c-7.6-4.4-17.4-1.8-21.8 6l-64 112c-4.4 7.7-1.7 17.5 6 21.8 2.5 1.4 5.2 2.1 7.9 2.1 5.5 0 10.9-2.9 13.9-8.1l64-112c4.4-7.6 1.7-17.4-6-21.8zM416 128c-.6 0-1.1.2-1.6.2 1.1-5.2 1.6-10.6 1.6-16.2 0-44.2-35.8-80-80-80-24.6 0-46.3 11.3-61 28.8C256.4 24.8 219.3 0 176 0 114.2 0 64 50.1 64 112c0 7.3.8 14.3 2.1 21.2C27.8 145.8 0 181.5 0 224c0 53 43 96 96 96h320c53 0 96-43 96-96s-43-96-96-96z">
                </path>
            </svg>
        </div>
    </div>
    

    <script>
        document.addEventListener("DOMContentLoaded", function () {
            var gateway = `ws://${window.location.hostname}/ws`;
            var websocket;

            var effects = [];

            function initWebSocket() {
                console.log("Trying to open a WebSocket connection...");
                websocket = new WebSocket(gateway);
                websocket.onopen = onOpen;
                websocket.onclose = onClose;
                websocket.onmessage = onMessage; // <-- add this line
            }

            function onOpen(event) {
                console.log("Connection opened");
            }

            function onClose(event) {
                console.log("Connection closed");
                setTimeout(initWebSocket, 2000);
            }

            function onMessage(event) {
                console.log(event.data);
                let timeData = JSON.parse(event.data);
                let container = document.getElementById("dataContainer");
                container.dataset.timeAmount = timeData.data.timeAmount;
                container.dataset.timeRepeats = timeData.data.timeRepeats;
                container.dataset.timeRemaining = timeData.data.timeRemaining;
            }

            var getNextSibling = function (elem, selector) {

                // Get the next sibling element
                var sibling = elem.nextElementSibling;

                // If the sibling matches our selector, use it
                // If not, jump to the next sibling and continue the loop
                while (sibling) {
                    if (sibling.matches(selector)) return sibling;
                    sibling = sibling.nextElementSibling
                }

            };

            document.querySelectorAll('.effects-button').forEach(item => {
                item.addEventListener('click', event => {
                    getNextSibling(item.closest(".card"), '.effects-container').classList.toggle("hidden");
                })
            })

            window.addEventListener("load", onLoad);

            function onLoad(event) {
                initWebSocket();
            }

            var lightsBedSwitch = false;
            document.getElementById("lightsBedSwitch").addEventListener("click", (e) => {
                lightsBedSwitch != lightsBedSwitch;
                // TDOOdocument.querySelector("#lightsBedSwitch svg").classList.toggle("fa-icons--inactive");
                websocket.send("command=updateState;active=" + lightsBedSwitch + ";controllerName=" + e.target.dataset.controllername +";");
            });
            
            
            document.querySelectorAll('.effect-button').forEach(item => {
                item.addEventListener('click', event => {
                websocket.send("command=updateEffect;controllerName=" + item.dataset.controllername +";effect=" + item.dataset.effectname + ";");
                })
            });

            
            document.getElementById("brightnessBed").addEventListener("change", () => {
              //console.log("command=updateBrightness;brightness=" + document.getElementById("brightnessBed").value + ";");
              websocket.send("command=updateBrightness;brightness=" + document.getElementById("brightnessBed").value + ";")
            });
        });
    </script>
</body>

</html>
)rawliteral";
