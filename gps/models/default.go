package models

import (
	"fmt"
	_ "github.com/astaxie/beego"
	"github.com/astaxie/beego/orm"
)

type Resp struct {
	Records []GpsT `json:"data"`
}

type GpsT struct {
	Id         int
	Longitude  float64 `json:"x"`
	Latitude   float64 `json:"y"`
	CreateTime string  `json:"create_time"`
}

func GetRecord() ([]GpsT, error) {
	o := orm.NewOrm()
	var tmp []GpsT
	var err error
	sql := "select * from gps_t order by id"
	if _, err = o.Raw(sql).QueryRows(&tmp); err != nil {
		fmt.Println("query table err = %+v", err)
		return tmp, err
	}
	return tmp, nil
}
