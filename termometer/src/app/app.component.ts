import { Component, OnInit } from '@angular/core';
import {
  IMqttMessage,
  IMqttServiceOptions,
  MqttService,
  IPublishOptions,
} from 'ngx-mqtt';
import { IClientSubscribeOptions } from 'mqtt-browser';
import { Subscription } from 'rxjs';
import { MQTT_SERVICE_OPTIONS } from './app.module';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss'],
})
export class AppComponent implements OnInit {
  title = 'termometer';

  subscription?: Subscription;
  public message?: string;

  constructor(private mqttService: MqttService) {
    mqttService.connect(MQTT_SERVICE_OPTIONS);
  }

  ngOnInit(): void {
    this.subscription = this.mqttService
      .observe('temperature')
      .subscribe((message: IMqttMessage) => {
        this.message = message.payload.toString();
        console.log(this.message);
      });
  }
}
