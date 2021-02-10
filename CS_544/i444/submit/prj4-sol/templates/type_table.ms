<h2>Results Summary</h2>
<table class="summary">
    <thead>
	   <tr>
              <th>Manufacturer</th>
              <th>Sensor Type ID</th>
              <th>Model Number</th>
              <th>Measure</th>
              <th colspan="2">Limits</th>
	   </tr>
	   <tr>
              <th></th>
              <th></th>
              <th></th>
              <th></th>
              <th>Min</th>
              <th>Max</th>
	   </tr>
     </thead>
     <tbody>
	 	{{#table_data.data}}
		<tr>
            <td class="tst-manufacturer">
				{{manufacturer}}
   			</td>
            <td class="tst-sensor-type-id">
  		 		{{id}}
			</td>
            <td class="tst-model-number">
  		   		{{modelNumber}}
  		 	</td>
            <td class="tst-quantity">
				{{quantity}}
  		 	</td>
            <td class="numeric interval tst-limits-min">
				{{#min}}
					{{min}}
				{{/min}}
				{{^min}}
				    {{#limits.min}}
					    {{limits.min}}
				    {{/limits.min}}
                    {{^limits.min}}
                        0
                    {{/limits.min}}
				{{/min}}
  		 	</td>
            <td class="numeric interval tst-limits-max">
				{{#max}}
					{{max}}
				{{/max}}
				{{^max}}
				    {{#limits.max}}
				    	{{limits.max}}
				    {{/limits.max}}
                    {{^limits.max}}
                        0
                    {{/limits.max}}
				{{/max}}
  		 	</td>
       	</tr>
		{{/table_data.data}}
 	</tbody>
</table>
