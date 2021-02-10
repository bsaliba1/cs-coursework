<h2>Results Summary</h2>
<table class="summary">
    <thead>
	   <tr>
              <th>Sensor ID</th>
              <th>Model</th>
              <th>Period</th>
              <th colspan="2">Expected Range</th>
	   </tr>
	   <tr>
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
            <td class="tst-sensor-id">
  		 		{{id}}
			</td>
            <td class="tst-model">
  		   		{{model}}
  		 	</td>
            <td class="tst-period numberic">
				{{period}}
  		 	</td>
            <td class="numeric interval tst-expected-min">
				{{#min}}
					{{min}}
				{{/min}}
				{{^min}}
				{{#expected.min}}
					{{expected.min}}
				{{/expected.min}}
				{{^expected.min}}
                    0
				{{/expected.min}}
				{{/min}}
  		 	</td>
            <td class="numeric interval tst-expected-max">
				{{#max}}
					{{max}}
				{{/max}}
				{{^max}}
				    {{#expected.max}}
				    	{{expected.max}}
				    {{/expected.max}}
				    {{^expected.max}}
                        0
				    {{/expected.max}}
                {{/max}}
  		 	</td>
       	</tr>
		{{/table_data.data}}
 	</tbody>
</table>
